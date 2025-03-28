## Задание MONTH

Вывести информацию о командировках, начало и конец которых относятся к одному месяцу (год может быть любой). В результат включить столбцы ```name```, ```city```, ```date_first```, ```date_last```. Строки отсортировать сначала  в алфавитном порядке по названию города, а затем по фамилии сотрудника .

Немного теории

Для того, чтобы выделить номер месяца из даты используется функция MONTH(дата).

Например, MONTH('2020-04-12') = 4.

Если определяется месяц для  значений столбца date_first, то используется запись MONTH(date_first)

*Решение*

```SQL
SELECT name, city, date_first, date_last  
  FROM trip
 WHERE MONTH(date_first) = MONTH(date_last) 
 ORDER BY city, name
```

**Результат**

```
Query result:
+---------------+-----------------+------------+------------+
| name          | city            | date_first | date_last  |
+---------------+-----------------+------------+------------+
| Абрамова К.А. | Владивосток     | 2020-01-14 | 2020-01-27 |
| Абрамова К.А. | Владивосток     | 2020-07-02 | 2020-07-13 |
| Баранов П.Е.  | Воронеж         | 2020-07-19 | 2020-07-25 |
| Абрамова К.А. | Москва          | 2020-04-06 | 2020-04-14 |
| Баранов П.Е.  | Москва          | 2020-01-12 | 2020-01-17 |
| Баранов П.Е.  | Москва          | 2020-02-14 | 2020-02-22 |
| Колесов С.П.  | Москва          | 2020-02-01 | 2020-02-06 |
| Лебедев Т.К.  | Москва          | 2020-03-03 | 2020-03-06 |
| Семенов И.В.  | Москва          | 2020-01-23 | 2020-01-31 |
| Колесов С.П.  | Новосибирск     | 2020-06-03 | 2020-06-12 |
| Семенов И.В.  | Санкт-Петербург | 2020-06-01 | 2020-06-03 |
| Лебедев Т.К.  | Томск           | 2020-05-20 | 2020-05-31 |
| Федорова А.Ю. | Томск           | 2020-06-20 | 2020-06-26 |
+---------------+-----------------+------------+------------+
Affected rows: 13
```

## Задание MONTHNAME

Вывести название месяца и количество командировок для каждого месяца. Считаем, что командировка относится к некоторому месяцу, если она началась в этом месяце. Информацию вывести сначала в отсортированном по убыванию количества, а потом в алфавитном порядке по названию месяца виде. Название столбцов – Месяц и Количество.

Немного теории

* Для того, чтобы выделить название месяца из даты используется функция MONTHNAME(дата), которая возвращает название месяца на английском языке для указанной даты. Например, MONTHNAME('2020-04-12')='April'.
* Если группировка осуществляется по вычисляемому столбцу (в данном случае «вычисляется» название месяца), то после GROUP BYможно указать как вычисляемое выражение, так и имя столбца, заданное с помощью AS. Важно отметить, что последний вариант (указать имя столбца)  нарушает стандарт по порядку выполнения запросов, но иногда может встречаться на реальных платформах.

```SQL
SELECT MONTHNAME(date_first) AS Месяц, 
       COUNT(MONTHNAME(date_first)) AS Количество
  FROM trip
 GROUP BY 1
 ORDER BY 2 DESC, 1 ASC
```

**Результат**
```
Query result:
+----------+------------+
| Месяц    | Количество |
+----------+------------+
| February | 4          |
| January  | 4          |
| June     | 3          |
| May      | 3          |
| April    | 2          |
| July     | 2          |
| March    | 2          |
+----------+------------+
Affected rows: 7
```

## Задание

Вывести сумму суточных (произведение количества дней командировки и размера суточных) для командировок, первый день которых пришелся на февраль или март 2020 года. Значение суточных для каждой командировки занесено в столбец per_diem. Вывести фамилию и инициалы сотрудника, город, первый день командировки и сумму суточных. Последний столбец назвать Сумма. Информацию отсортировать сначала  в алфавитном порядке по фамилиям сотрудников, а затем по убыванию суммы суточных.

1. В SQL есть функции, которые позволяют выделить часть даты: день(DAY()), месяц (MONTH()), год(YEAR()) . Например:

* AY('2020-02-01') = 1
* MONTH('2020-02-01') = 2
* YEAR('2020-02-01') = 2020

2. Количество дней командировки вычисляется как разница между датами последнего и первого дня командировки плюс 1.

**Запрос**
```SQL
SELECT name, city, date_first, 
       per_diem * (DATEDIFF(date_last, date_first) + 1) AS Сумма
  FROM trip
 WHERE (MONTH(date_first) = 2) OR (MONTH(date_first) = 3)
 ORDER BY name ASC, 
          СУММА DESC
```

*Результат*
```
+---------------+-----------------+------------+---------+
| name          | city            | date_first | Сумма   |
+---------------+-----------------+------------+---------+
| Абрамова К.А. | Москва          | 2020-02-23 | 5600.00 |
| Баранов П.Е.  | Москва          | 2020-02-14 | 6300.00 |
| Колесов С.П.  | Новосибирск     | 2020-02-27 | 6750.00 |
| Колесов С.П.  | Москва          | 2020-02-01 | 4200.00 |
| Лебедев Т.К.  | Москва          | 2020-03-03 | 2800.00 |
| Семенов И.В.  | Санкт-Петербург | 2020-03-29 | 5600.00 |
```

## Задание

Вывести фамилию с инициалами и общую сумму суточных, полученных за все командировки для тех сотрудников, которые были в командировках больше чем 3 раза, в отсортированном по убыванию сумм суточных виде. Последний столбец назвать Сумма.

Только для этого задания изменена строка таблицы trip:
```
4 	Ильиных Г.Р. 	Владивосток 	450 	2020-01-12 	2020-03-02
```

**Запрос**
```SQL
SELECT name, 
       SUM(per_diem * (DATEDIFF(date_last, date_first)+1)) AS Сумма
  FROM trip
 GROUP BY name
HAVING COUNT(name) > 3 
 ORDER BY Сумма DESC
```
*Результат*

```
+---------------+----------+
| name          | Сумма    |
+---------------+----------+
| Абрамова К.А. | 29200.00 |
| Баранов П.Е.  | 21300.00 |
+---------------+----------+
```

