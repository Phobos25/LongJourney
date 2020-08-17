# Nested and Repeated data

До сих пор мы рассматривали простые таблицы. Это таблицы у которых в столбцах одинаковое количество данных: 
```
pets table                  toys   table       
ID Name     Age  Animal     ID  Name     Type    Pet_ID
1  Moon      9   Dog        1   McFly   Frisbee  1
2  Ripley    7   Cat        2   Fluffy  Feather  2
3  Napoleon  1   Fish       3   Eddy    Castle   3
```

Другой вариант хранения данных это когда эти две таблицы объединены в общую таблицу pets_and_toys


# Вложенные данные
```
pets_and_toys table
ID Name     Age  Animal   Toy
1  Moon      9   Dog      {Name: McFly,  Type: Frisbee}
2  Ripley    7   Cat      {Name: Fluffy, Type: Feather}
3  Napoleon  1   Fish     {Name: Eddy,   Type: Castle }
```

В этом случае, вся информация из таблицы toys была помещена в столбец Toy. Такой столбец называется **вложенным** (nested) и столбцы "Name" и "Type" вложены внутри. 

Вложенные столбцы имеют тип **STRUCT** (или тип **RECORD**).

Чтобы получить к ним доступ мы должны указать название столбца и типа данных, которых хотим вызвать. 
* Toy.Name - вызывает данные из **Name** в столбце **Toy**
* Toy.Type - вызывает данные из **Type** в столбце **Toy**

```
query = """
        SELECT   Name AS Pet_Name,
                 Toy.Name AS Toy_Name,
                 Toy.Type AS Toy_Type
        FROM     `bigquery-public-data.pet_records.pet_and_toys`
        """
```

# Повторяющиеся данные
**Повторяющиеся данные**. Давайте рассмотрим более реалистичную таблицу, когда у питомцев по несколько игрушек:

```
pets_and_toys table
ID Name     Age  Animal   Toy
1  Moon      9   Dog      [Frisbee, Bone, Rope]
2  Ripley    7   Cat      [Feather, Ball]
3  Napoleon  1   Fish     [Castle] 
```
В этом случае столбец "Toys" содержит **повторяющиеся данные** (repeated data), потому что содержит более одного значения на каждой строке. 
Данные представляют собой массив (**ARRAY**), или упорядоченный список одного типа. 

Для вызова таких данные мы должны использовать функцию **UNNEST()**
```
query = """
        SELECT   Name AS Pet_Name,
                 Toy_Type
        FROM     `bigquery-public-data.pet_records.pets_and_toys_type`
                 UNNEST(Toys) AS Toy_Type
        """
```

По существу, эта функция разглаживает столбец с повторяющимися данными и у нас получается по одному элементу на каждой строке:
```
Pet_Name    Toy_Type
Moon        Frisbee
Moon        Bone 
Moon        Rope
Ripley      Feather
Ripley      Ball
Napoleon    Castle
```

# Вложенные и повторяющиеся данные

Что делать, если у питомцев по несколько игрушек и мы хотели бы записать и имя и тип игрушки. В этом случае, столбец "Toys" будет одновременно и вложенным, и повторяющимся. 

```
pets_and_toys table
ID Name     Age  Animal   Toys
1  Moon      9   Dog      [{Name: McFly, Type: Frisbee},
                           {Name: Scully, Type: Bone}, 
                           {Name: Pusheen, Type: Rope}]
2  Ripley    7   Cat      [{Name: Fluffy, Type: Feather},
                            {Name: Robert, Type: Ball}]
3  Napoleon  1   Fish     [{Name: Eddy, Type: Castle}] 
```

Пример:
```
query = """
        SELECT   Name AS Pet_Name,
                 t.Name AS Toy_Name,
                 t.Type AS Toy_Type
        FROM     `bigquery-public-data.pet_records.more_pets_and_toys`,
                 UNNEST(Toys) AS t
        """
```

Т.к. столбец "Toys" содержит вложенные данные, мы разглаживаем его функцией **UNNEST()**. И т.к. мы дали разглаженному столбцу обозначение t, мы можем вызывать "Name" и "Toys" при помощи t.

# Writing efficient queries

Время от времени нам бывают нужно написать эффективный запрос. Если мы работаме с маленькой базой данных, или посылаем запрос только один раз, то особой необходимости в написании эффективных запросов нет. Нужна в них появляется при определенных условиях, например, если мы отправляем данные на сайт, мы не хотим, чтобы юзер очень долго ждал, пока сайт прогрузится. Или если у нас база данных колоссальных размеров, то неэффективный запрос может стоить бизнесу больших денег. 

Большинство баз данных используют различнго рода оптимизаторы, чтобы попытаться оптимизировать вам неэффективный запрос. Но определенные стратегии, которые вы можете применить сами, позволяют сильно сократить время обработки вашего запроса. 

Если хотите оценить эффективность вашего запроса вы можете использовать следующие команды/функции:
* show_amount_of_data_scanned() --- показывает размер данных, которые использует ваш запрос
* show_time_to_run() --- выводит длительность обработки вашего запроса

# Стратегии для написания эффективного запроса
1) **Выбирайте только те столбцы, которые вам нужны.**

Давайте рассмотрим пример:
```
star_query = "SELECT * FROM    `bigquery-public-data.github_repos.contents"
show_amount_of_data_scanned(star_query)

basic_query = "SELECT size, binary FROM `bigquery-public-data.github_repos.contents`"
show_amount_of_data_scanned(basic_query)
```
на выходе получаем:
```
Data processed: 2504.697 GB
Data processed: 2.396 GB
```
как мы видим, разница в 1000 раз. 

2. **Читаем меньше данных**

Для примера рассмотрим два запроса одних и тех же данных. Данные представляют собой среднюю длительность (в секундах) путешествия на велосипеде в Сан-Франциско. 

```
more_data_query = """
                  SELECT MIN(start_station_name) AS start_station_name,
                      MIN(end_station_name) AS end_station_name,
                      AVG(duration_sec) AS avg_duration_sec
                  FROM `bigquery-public-data.san_francisco.bikeshare_trips`
                  WHERE start_station_id != end_station_id 
                  GROUP BY start_station_id, end_station_id
                  LIMIT 10
                  """
show_amount_of_data_scanned(more_data_query)

less_data_query = """
                  SELECT start_station_name,
                      end_station_name,
                      AVG(duration_sec) AS avg_duration_sec                  
                  FROM `bigquery-public-data.san_francisco.bikeshare_trips`
                  WHERE start_station_name != end_station_name
                  GROUP BY start_station_name, end_station_name
                  LIMIT 10
                  """
show_amount_of_data_scanned(less_data_query)
```

```
Data processed: 0.076 GB
Data processed: 0.06 Gb
```

По сути station ID и station name это одно и то же --- уникальные названия остановок, нам не надо использовать start_station_id и end_station_id
Мы можем использовать  start_station_name и end_station_name, который уже используется для расчета времени путешествия. 

3. **Избегайте N:N JOIN**

Почти все соединения таблиц, который мы рассмотрели представляли собой 1:1 JOIN, т.е. каждая строка, каждой таблицы совпадала максимум с одной строкой из другой таблицы. 

Другой тип --- это N:1 JOIN, это когда каждая строка одной таблицы потенциально совпадает со множеством строк другой таблицы. 

Третий тип --- это N:N JOIN, это когда группа строк одной таблицы может совпадать с группой строк другой таблицы. 

Для сравнения, рассмотрим пример:
```
big_join_query = """
                 SELECT repo,
                     COUNT(DISTINCT c.committer.name) as num_committers,
                     COUNT(DISTINCT f.id) AS num_files
                 FROM `bigquery-public-data.github_repos.commits` AS c,
                     UNNEST(c.repo_name) AS repo
                 INNER JOIN `bigquery-public-data.github_repos.files` AS f
                     ON f.repo_name = repo
                 WHERE f.repo_name IN ( 'tensorflow/tensorflow', 'facebook/react', 'twbs/bootstrap', 'apple/swift', 'Microsoft/vscode', 'torvalds/linux')
                 GROUP BY repo
                 ORDER BY repo
                 """
show_time_to_run(big_join_query)

small_join_query = """
                   WITH commits AS
                   (
                   SELECT COUNT(DISTINCT committer.name) AS num_committers, repo
                   FROM `bigquery-public-data.github_repos.commits`,
                       UNNEST(repo_name) as repo
                   WHERE repo IN ( 'tensorflow/tensorflow', 'facebook/react', 'twbs/bootstrap', 'apple/swift', 'Microsoft/vscode', 'torvalds/linux')
                   GROUP BY repo
                   ),
                   files AS 
                   (
                   SELECT COUNT(DISTINCT id) AS num_files, repo_name as repo
                   FROM `bigquery-public-data.github_repos.files`
                   WHERE repo_name IN ( 'tensorflow/tensorflow', 'facebook/react', 'twbs/bootstrap', 'apple/swift', 'Microsoft/vscode', 'torvalds/linux')
                   GROUP BY repo
                   )
                   SELECT commits.repo, commits.num_committers, files.num_files
                   FROM commits 
                   INNER JOIN files
                       ON commits.repo = files.repo
                   ORDER BY repo
                   """

show_time_to_run(small_join_query)
```
Output:
```
Time to run: 9.06 seconds
Time to run: 10.798 seconds
```









