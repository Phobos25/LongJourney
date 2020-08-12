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

# Repeated data
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

