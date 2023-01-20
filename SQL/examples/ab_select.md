# Задание

Вывести абитуриентов, которые хотят поступать на образовательную программу «Мехатроника и робототехника» в отсортированном по фамилиям виде.

```SQL
SELECT name_enrollee
  FROM 
       enrollee
       INNER JOIN program_enrollee ON enrollee.enrollee_id = program_enrollee.enrollee_id
       INNER JOIN program          ON program_enrollee.program_id = program.program_id
 WHERE name_program = 'Мехатроника и робототехника'
 ORDER BY name_enrollee;
```

```
Query result:
+-----------------+
| name_enrollee   |
+-----------------+
| Баранов Павел   |
| Попов Илья      |
| Семенов Иван    |
| Степанова Дарья |
+-----------------+
Affected rows: 4
```

# Задание

Вывести образовательные программы, на которые для поступления необходим предмет «Информатика». Программы отсортировать в обратном алфавитном порядке.
```SQL
SELECT name_program
  FROM
       subject
       INNER JOIN program_subject ON program_subject.subject_id = subject.subject_id
       INNER JOIN program         ON program_subject.program_id = program.program_id
 WHERE name_subject = 'Информатика'
 ORDER BY name_program DESC;

```

```
Query result:
+-------------------------------------+
| name_program                        |
+-------------------------------------+
| Прикладная математика и информатика |
| Математика и компьютерные науки     |
+-------------------------------------+
Affected rows: 2
```

# Задание

Выведите количество абитуриентов, сдавших ЕГЭ по каждому предмету, максимальное, минимальное и среднее значение баллов по предмету ЕГЭ. Вычисляемые столбцы назвать ```Количество```, ```Максимум```, ```Минимум```, ```Среднее```. Информацию отсортировать по названию предмета в алфавитном порядке, среднее значение округлить до одного знака после запятой.
```SQL
SELECT name_subject, COUNT(DISTINCT enrollee_id) AS Количество,
       MAX(result) AS Максимум,
       MIN(result) AS Минимум,
       ROUND(AVG(result), 1) AS Среднее
  FROM 
       subject
       INNER JOIN enrollee_subject USING(subject_id)
 GROUP BY name_subject
 ORDER BY name_subject;
```

```
Query result:
+--------------+------------+----------+---------+---------+
| name_subject | Количество | Максимум | Минимум | Среднее |
+--------------+------------+----------+---------+---------+
| Информатика  | 4          | 94       | 75      | 82.0    |
| Математика   | 6          | 92       | 67      | 75.3    |
| Русский язык | 6          | 90       | 65      | 77.5    |
| Физика       | 5          | 90       | 41      | 69.8    |
+--------------+------------+----------+---------+---------+
Affected rows: 4
```
# Задание

Вывести образовательные программы, для которых минимальный балл ЕГЭ по каждому предмету больше или равен 40 баллам. Программы вывести в отсортированном по алфавиту виде.

```SQL
SELECT name_program
  FROM 
       program INNER JOIN program_subject USING(program_id)
 GROUP BY name_program
HAVING MIN(min_result) >= 40
 ORDER BY name_program
```

```
Query result:
+-------------------------------------+
| name_program                        |
+-------------------------------------+
| Мехатроника и робототехника         |
| Прикладная математика и информатика |
+-------------------------------------+
Affected rows: 2
```
# Задание

Вывести образовательные программы, которые имеют самый большой план набора,  вместе с этой величиной.
```SQL
SELECT name_program, plan
  FROM program
 WHERE plan = (SELECT MAX(plan) FROM program)
```

```
Query result:
+-----------------------------+------+
| name_program                | plan |
+-----------------------------+------+
| Мехатроника и робототехника | 3    |
+-----------------------------+------+
Affected rows: 1
```
# Задание

Посчитать, сколько дополнительных баллов получит каждый абитуриент. Столбец с дополнительными баллами назвать Бонус. Информацию вывести в отсортированном по фамилиям виде.
```SQL
SELECT name_enrollee, IF(SUM(bonus) IS NULL, 0, SUM(bonus)) AS Бонус
  FROM 
       enrollee
        LEFT JOIN enrollee_achievement USING(enrollee_id)
        LEFT JOIN achievement          USING(achievement_id)
 GROUP BY name_enrollee
 ORDER BY name_enrollee
```

**Результат**
```
Query result:
+-----------------+-------+
| name_enrollee   | Бонус |
+-----------------+-------+
| Абрамова Катя   | 0     |
| Баранов Павел   | 6     |
| Попов Илья      | 8     |
| Семенов Иван    | 5     |
| Степанова Дарья | 0     |
| Яковлева Галина | 1     |
+-----------------+-------+
Affected rows: 6
```
# Задание

Выведите сколько человек подало заявление на каждую образовательную программу и конкурс на нее (число поданных заявлений деленное на количество мест по плану), округленный до 2-х знаков после запятой. В запросе вывести название факультета, к которому относится образовательная программа, название образовательной программы, план набора абитуриентов на образовательную программу (plan), количество поданных заявлений (Количество) и Конкурс. Информацию отсортировать в порядке убывания конкурса.

```SQL
SELECT name_department, name_program, plan, 
       COUNT(enrollee_id) AS Количество,
       ROUND(COUNT(enrollee_id)/plan, 2) AS Конкурс
  FROM 
       department
       INNER JOIN program          ON department.department_id = program.department_id
       INNER JOIN program_enrollee ON program.program_id = program_enrollee.program_id
 GROUP BY name_department, name_program, plan
 ORDER BY Конкурс DESC
```

**Результат**
```
Query result:
+-------------------------+-------------------------------------+------+------------+---------+
| name_department         | name_program                        | plan | Количество | Конкурс |
+-------------------------+-------------------------------------+------+------------+---------+
| Школа естественных наук | Математика и компьютерные науки     | 1    | 3          | 3.00    |
| Инженерная школа        | Прикладная механика                 | 2    | 4          | 2.00    |
| Школа естественных наук | Прикладная математика и информатика | 2    | 3          | 1.50    |
| Инженерная школа        | Мехатроника и робототехника         | 3    | 4          | 1.33    |
+-------------------------+-------------------------------------+------+------------+---------+
Affected rows: 4
```

# Задание

Вывести образовательные программы, на которые для поступления необходимы предмет «Информатика» и «Математика» в отсортированном по названию программ виде.
```SQL
SELECT name_program
  FROM 
       program
       INNER JOIN program_subject ON program.program_id = program_subject.program_id
       INNER JOIN subject         ON program_subject.subject_id = subject.subject_id
 WHERE name_subject IN ('Математика', 'Информатика')
 GROUP BY name_program
HAVING COUNT(program_subject.subject_id) = 2
 ORDER BY name_program
```
Результат
```
Query result:
+-------------------------------------+
| name_program                        |
+-------------------------------------+
| Математика и компьютерные науки     |
| Прикладная математика и информатика |
+-------------------------------------+
Affected rows: 2
```

# Задание

Посчитать количество баллов каждого абитуриента на каждую образовательную программу, на которую он подал заявление, по результатам ЕГЭ. В результат включить название образовательной программы, фамилию и имя абитуриента, а также столбец с суммой баллов, который назвать itog. Информацию вывести в отсортированном сначала по образовательной программе, а потом по убыванию суммы баллов виде.
```SQL
SELECT name_program, name_enrollee, SUM(result) AS itog
  FROM 
       enrollee
       INNER JOIN program_enrollee ON enrollee.enrollee_id = program_enrollee.enrollee_id
       INNER JOIN program          ON program_enrollee.program_id = program.program_id
       INNER JOIN program_subject  ON program.program_id = program_subject.program_id
       INNER JOIN subject          ON program_subject.subject_id = subject.subject_id
       INNER JOIN enrollee_subject ON subject.subject_id = enrollee_subject.subject_id 
                                  AND enrollee_subject.enrollee_id = enrollee.enrollee_id
 GROUP BY name_program, name_enrollee
 ORDER BY name_program, itog DESC
```
Результат
```
Query result:
+-------------------------------------+-----------------+------+
| name_program                        | name_enrollee   | itog |
+-------------------------------------+-----------------+------+
| Математика и компьютерные науки     | Степанова Дарья | 276  |
| Математика и компьютерные науки     | Семенов Иван    | 230  |
| Математика и компьютерные науки     | Абрамова Катя   | 226  |
| Мехатроника и робототехника         | Степанова Дарья | 270  |
| Мехатроника и робототехника         | Семенов Иван    | 242  |
| Мехатроника и робототехника         | Попов Илья      | 192  |
| Мехатроника и робототехника         | Баранов Павел   | 179  |
| Прикладная математика и информатика | Семенов Иван    | 230  |
| Прикладная математика и информатика | Абрамова Катя   | 226  |
| Прикладная математика и информатика | Баранов Павел   | 213  |
| Прикладная механика                 | Степанова Дарья | 270  |
| Прикладная механика                 | Яковлева Галина | 238  |
| Прикладная механика                 | Попов Илья      | 192  |
| Прикладная механика                 | Баранов Павел   | 179  |
+-------------------------------------+-----------------+------+
Affected rows: 14
```

# Задание

Вывести название образовательной программы и фамилию тех абитуриентов, которые подавали документы на эту образовательную программу, но не могут быть зачислены на нее. Эти абитуриенты имеют результат по одному или нескольким предметам ЕГЭ, необходимым для поступления на эту образовательную программу, меньше минимального балла. Информацию вывести в отсортированном сначала по программам, а потом по фамилиям абитуриентов виде.

Например, Баранов Павел по «Физике» набрал 41 балл, а  для образовательной программы «Прикладная механика» минимальный балл по этому предмету определен в 45 баллов. Следовательно, абитуриент на данную программу не может поступить.

```SQL
SELECT DISTINCT name_program, name_enrollee
  FROM 
       enrollee
       INNER JOIN program_enrollee ON enrollee.enrollee_id = program_enrollee.enrollee_id
       INNER JOIN program          ON program_enrollee.program_id = program.program_id
       INNER JOIN program_subject  ON program.program_id = program_subject.program_id
       INNER JOIN subject          ON program_subject.subject_id = subject.subject_id
       INNER JOIN enrollee_subject ON subject.subject_id = enrollee_subject.subject_id 
                                  AND enrollee_subject.enrollee_id = enrollee.enrollee_id
 WHERE result < min_result
 GROUP BY name_program, name_enrollee
 ORDER BY name_program

```

```
Query result:
+-----------------------------+---------------+
| name_program                | name_enrollee |
+-----------------------------+---------------+
| Мехатроника и робототехника | Баранов Павел |
| Прикладная механика         | Баранов Павел |
+-----------------------------+---------------+
Affected rows: 2
```