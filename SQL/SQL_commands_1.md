# Intro_to_SQL
collapsed:: true
	- Для SQL пишется query, который используется как команда для загрузки необходимой информации с базы данных. Т.к. база данных может быть очень большой (несколько терабайт), и не все данные нужны, поэтому надо использовать такой способ, чтобы не загружать все данные. Для этого используется query --- список команд, для SQL. 
	  
	  Пример: 
	  
	  ```
	  query = """
	        SELECT id, title, owner_user_id
	        FROM `bigquery-public-data.stackoverflow.posts_questions`
	        WHERE tags LIKE '%bigquery%'
	        """
	  ```
	  
	  Здесь, 
	  [[Select_from]] --- это названия столбцов, которые мы хотим загрузить. 
	  [[FROM]] --- это адрес или название базы данных
	  [[WHERE]] --- дополнительное условие для фильтрации данных, в нашем случае мы добавили [[LIKE]] , который позволяет искать данные в столбцах, которые содержат определенные значения. В нашем случае --- 'bigquery', % --- любое значение. 
	  Т.е. любой текст, которые содержит слово bigquery: '12314bigquery-something', ' bigquery435' и т.д. 
	  
	  Далее, рассмотрим случай, когда нам надо получить данные из разных таблиц, или даже разных баз данных. 
	  
	  ```
	  query = """
	        SELECT a.id, a.body, a.owner_user_id
	        FROM `bigquery-public-data.stackoverflow.posts_questions` AS q 
	        INNER JOIN `bigquery-public-data.stackoverflow.posts_answers` AS a
	            ON q.id = a.parent_id
	        WHERE q.tags LIKE '%bigquery%'
	        """
	  ```
	  
	  Для этого используется команда [[INNER JOIN]] и ON. INNER JOIN --- дополнительная таблица, ON --- столбец, по которому таблицы объединяются. Надо иметь в виду, что у таблиц, должен быть совпадающий столбец.
	  
	  Следующая команда --- это WITH:
	  ```
	  rides_per_year_query = '''
	        WITH time AS
	        (
	            SELECT EXTRACT(YEAR FROM trip_start_timestamp) as year
	            FROM `bigquery-public-data.chicago_taxi_trips.taxi_trips`
	        )
	        SELECT COUNT(1) AS num_trips, year
	        FROM time
	        GROUP BY year
	        ORDER BY year
	        '''
	  ```
	  
	  Эта команда используется для удобства, своего рода, функция в языках программирования. Чтобы повысить читаемость, уменьшить вероятность ошибки.
- # GROUP BY, HAVING, COUNT()
  collapsed:: true
	- **COUNT()** возвращает число строк в столбце, если вставить название столбца, к примеру ** [[COUNT]] (col).**
	  Это аггрегирующая функция, т.е. функция которая принимает много значений, но вовзращает одно. Другие такие функции: **SUM()**, **AVG()**, **MIN()**, **MAX()**.
	  
	  ** [[GROUP BY]] ()** --- использует имя одного или нескольких столбцов и группирует их. Если использовать совместно с **COUNT()**:
	  
	  ```
	  query = """
	        SELECT Animal, COUNT(ID) AS Num
	        FROM `bigquery-public-data.pet_records.pets`
	        GROUP BY Animal
	        """
	  ```
	  Мы получим таблицу, которая будет показывать сколько каждого типа животных (Animal) есть в таблице.
	  
	  ```
	  Animal     Num
	  Rabbit      1
	  Dog         1
	  Cat         2
	  ```
	  
	  ** [[HAVING]] ** используется совместно с [[GROUP BY]] для задания дополнительных условий фильтрации и поиска данных. Пример:
	  ```
	  query = """
	        SELECT Animal, COUNT(ID) AS Num
	        FROM `bigquery-public-data.pet_records.pets`
	        GROUP BY Animal
	        HAVING COUNT(ID) > 1
	        """
	  ```
	  Получим:
	  ```
	  Animal  Num
	  Cat      2
	  ```
	  Т.к. только одна группа удовлетворяет нашему критерию (больше 1), наш query будет возвращать таблицу с одной строкой.
- # JOIN LEFT, UNION
  collapsed:: true
	- ** [[INNER JOIN]] ** соединяет только по совпадающим значениям. Если в столбце есть значения, которые не совпадают, или отсутствуют данные, то они выбрасываются. 
	  ```
	  owners table                        pets table        
	  ID   Name           Age   Pet_ID    ID Name     Age  Animal 
	  1  Aubrey Little    20      1       1  Bonkers   1   Rabbit
	  2  Chett Crawfish   45      3       2  Moon      9   Dog
	  3  Jules Spinner    10      4       3  Ripley    7   Cat
	  4  Magnus Burnsides 9       2       4  Tom       2   Cat
	  5  Veronica Dunn    8      NULL     5  Maisie    10  Dog
	  ```
	  
	  Сравнивая две таблицы, видно, что у Veronica Dunn нет питомца, и у собаки Maisie нет хозяина, т.к. номер 5 не появляется в таблице хозяев. 
	  
	  Если мы используем **INNER JOIN** по Pet_ID (owners table) и ID (pets table), то Veronica Dunn и Maisie в общую таблицу не попадут. 
	  Если мы хотим включить все данные из таблицы owners table, мы можем использовать **LEFT JOIN**. Здесь LEFT имеется в виду, таблица, которая идет первой. Пр.:
	  ```
	  `bigquery-public-data.pet_records.owners` AS o INNER JOIN `bigquery-public-data.pet_records.pets AS p`
	  ```
	  Таблица хозяев идет первой, поэтому она будет *left table*, а таблица питомцев *right table*. 
	  
	  Если мы хотим включить все данные из обоих таблиц, мы используем **FULL JOIN**. Следует иметь в виду, что отсутствующие данные будут заменены на NULL.
	  ```
	  FULL JOIN
	  Owner_Name          Pet_Name
	  Aubrey Little        Bonkers
	  Magnus Burnsides     Moon
	  Chett Crawfish       Ripley
	  Jules Spinner        Tom
	  Veronica Dunn        NULL
	  NULL                 Maisie
	  ```
	  
	  Если ** [[JOIN]] ** объединяет горизонтально, то ** [[UNION]] ** объединяет вертикально 
	  ```
	  query = """
	        SELECT Age FROM `bigquery-public-data.pet_records.pets`
	        UNION ALL
	        SELECT Age FROM `bigquery-public-data.pet_records.owners`
	        """
	  
	  Age
	  20
	  45
	  10
	  9
	  8
	  1
	  9
	  7
	  2
	  10
	  ```
	  Как видно в таблице присутствуют дубликаты. Это происходит из-за команды ** [[UNION ALL]] **, если использовать ** [[UNION DISTINCT]] **, то дубликатов не будет.
	  
	  В реальном случае, иногда приходится объединять, получать информацию с больше чем двух таблиц. Пример такой команды приведен ниже:
	  ```
	  query = """
	        SELECT o.Name AS Owner_Name,
	               p.Name AS Pet_name, 
	               t.Treat AS Fav_Treat    
	        FROM `bigquery-public-data.pet_records.pets` AS p 
	        FULL JOIN `bigquery-public-data.pet_records.owners` AS o
	            ON p.ID = o.Pet_ID
	        LEFT JOIN `bigquery-public-data.pet_records.treats` AS t
	            ON p.ID = t.Pet_ID
	        """
	  ```
	- Примеры использования [[JOIN]] [[INNER JOIN]]  приводятся в [[SQL_INNER_join]] и [[SQL_INNER_JOIN_2]]
- # Advanced Aggregate Functions
  collapsed:: true
	- Пускай у нас есть два бегуна --- которые обозначены 1 или 2 *id*, которые в определенные даты *date* уделяли определенное время *time* на тренировки. Мы хотим подсчитать движущееся среднее (moving average) для этих бегунов. 
	  
	  Рассмотрим следующий query:
	  ```
	  query = """
	        SELECT * 
	            AVG(time) OVER(
	                          PARTIION BY id
	                          ORDER BY date
	                          ROWS BETWEEN 1 PRECEDING AND CURRENT ROW
	                         ) AS avg_time
	           FROM `bigquery-public-data.runners.train_time`
	        """
	  ```
	  
	  Все аналитические функции имеют условие **OVER**, которое определяет наборы строк используемые для каждого вычисления. У условия **OVER** есть три опциональных (необязательных) части:
	  * **PARTITION BY** --- разделяет строки на разные группы. В нашем примере мы использовали *id*, т.е. разделили бегунов на две группы. 
	  * **ORDER BY** --- определяет сортировку. В нашем примере мы использовали *date*, т.е. ранние даты будут располагаться выше. 
	  * **ROWS BETWEEN 1 PRECEDING AND CURRENT ROW** --- также известен, как *временное окно* (window frame). Он определяет число строк, которые будут исопльзоваться в каждом вычислении. 
	  
	  Window framce clauses примеры:
	  * **ROWS BETWEEN 1 PRECEDING AND CURRENT ROW** --- предыдущая строка и текущая строка
	  * **ROWS BETWEEN 3 PRECEDING AND 1 FOLLOWING** --- 3 предыдущие строки, текущая строка, и следующая строка
	  * **ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING** --- все строки
	  
	  Выше, мы рассмотрели только одну из многих аналитических функций. BigQuery поддерживает множество других, про которые можно прочитать в [документации](https://cloud.google.com/bigquery/docs/reference/standard-sql/analytic-function-concepts).
	  
	  1) Аналитические функции аггрегаторы (analytic aggregate functions. *Aggregate* --- *formed or calculated by the combination of many separate units or items; total*)
	  Функции аггрегаторы берут все значения в окне и возвращают одно значение. 
	  
	  * **MIN()** (or **MAX()**) --- возвращает минимум (или максимум) из входных значений
	  * **AVG()** (or **SUM()**) --- возвращает среднее (или сумму) входных значений
	  * **COUNT()** --- возвращает число строк входных данных.
	  
	  2) Аналитические навигационные функции (Analytic navigation functions)
	  **Навигационные функции** присваивают значение на основе значения в строке (обычно), отличной от текущей. 
	  
	  * **FIRST_VALUE** (or **LAST_VALUE()**) --- возвращает первое (или последнее) значение во входных данных
	  * **LEAD()** (and **LAG()**) --- возвращает значение следующей (или предыдущей) строки.
	  
	  3) Аналитические нумерующие функции (Analytic numbering functions)
	  **Нумерующие функции** присваивают целочисленные значения к каждой строке исходя из порядка.
	  
	  * **ROW_NUMBER()** --- возвращает порядок, в котором строки появляется во входных данных (начиная с 1)
	  * **RANK()** --- All rows with the same value in the ordering column receive the same rank value, where the next row receives a rank value which increments by the number of rows with the previous rank value.