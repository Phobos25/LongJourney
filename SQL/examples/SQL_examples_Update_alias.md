# Использование временного имени таблицы (алиаса)

Теоретический материал для этого шага подготовлен Михаилом Захаровым . Большое ему спасибо!

Чтобы не писать название таблицы каждый раз, удобно использовать алиасы.

Алиас, это псевдоним, который мы присваивали столбцам после ключевого слова AS(шаг).  Алиасы так же можно использовать и для таблиц. Это становится актуальным, при увеличении числа используемых таблиц, их иногда может быть и 5 и 10 и более. Псевдонимы помогают сделать запрос чище и читабельнее.

Для присваивания псевдонима существует 2 варианта: 

    с использованием ключевого слова AS 
```SQL
FROM fine AS f, traffic_violation AS tv
```
    а так же и без него
```SQL
FROM fine f, traffic_violation tv
```
После присвоения таблице алиаса, он используется во всех разделах запроса, в котором алиас задан. Например:
```SQL
WHERE f.violation = tv.violation
```
**Пример**

Для тех, кто уже оплатил штраф, вывести информацию о том, изменялась ли стандартная сумма штрафа.

Запрос:
```SQL
SELECT  f.name, f.number_plate, f.violation,
   if(
    f.sum_fine = tv.sum_fine, "Стандартная сумма штрафа",
    if(
      f.sum_fine < tv.sum_fine, "Уменьшенная сумма штрафа", "Увеличенная сумма штрафа"
    )
  ) AS description               
FROM  fine f, traffic_violation tv
WHERE tv.violation = f.violation and f.sum_fine IS NOT Null;
```

Результат: 
```
+---------------+--------------+----------------------------------+--------------------------+
| name          | number_plate | violation                        | description              |
+---------------+--------------+----------------------------------+--------------------------+
| Баранов П.Е.  | Р523ВТ       | Превышение скорости(от 40 до 60) | Уменьшенная сумма штрафа |
| Абрамова К.А. | О111АВ       | Проезд на запрещающий сигнал     | Стандартная сумма штрафа |
| Яковлев Г.Р.  | Т330ТТ       | Превышение скорости(от 20 до 40) | Стандартная сумма штрафа |
+---------------+--------------+----------------------------------+--------------------------+
```
## Задание

Занести в таблицу fine суммы штрафов, которые должен оплатить водитель, в соответствии с данными из таблицы traffic_violation. При этом суммы заносить только в пустые поля столбца  sum_fine.

Таблица traffic_violationсоздана и заполнена.

Важно! Сравнение значения столбца с пустым значением осуществляется с помощью оператора IS NULL.

**Запрос**
```
UPDATE fine AS f, traffic_violation AS tv
   SET f.sum_fine = tv.sum_fine
 WHERE (f.sum_fine IS Null) AND (f.violation = tv.violation);
```

*Результат*
```
+---------------+--------+------------------------------+----------+----------------+--------------+
| name          | number | violation                    | sum_fine | date_violation | date_payment |
|               | _plate |                              |          |                |              |
+---------------+--------+------------------------------+----------+----------------+--------------+
| Баранов П.Е.  | Р523ВТ | Превышение скорости(от 40... | 500.00   | 2020-01-12     | 2020-01-17   |
| Абрамова К.А. | О111АВ | Проезд на запрещающий сигнал | 1000.00  | 2020-01-14     | 2020-02-27   |
| Яковлев Г.Р.  | Т330ТТ | Превышение скорости(от 20... | 500.00   | 2020-01-23     | 2020-02-23   |
| Яковлев Г.Р.  | М701АА | Превышение скорости(от 20... | 500.00   | 2020-01-12     | NULL         |
| Колесов С.П.  | К892АХ | Превышение скорости(от 20... | 500.00   | 2020-02-01     | NULL         |
| Баранов П.Е.  | Р523ВТ | Превышение скорости(от 40... | 1000.00  | 2020-02-14     | NULL         |
| Абрамова К.А. | О111АВ | Проезд на запрещающий сигн...| 1000.00  | 2020-02-23     | NULL         |
| Яковлев Г.Р.  | Т330ТТ | Проезд на запрещающий сигн...| 1000.00  | 2020-03-03     | NULL         |
+---------------+--------+------------------------------+----------+----------------+--------------+
```

# Группировка данных по нескольким столбцам

## Задание

Вывести фамилию, номер машины и нарушение только для тех водителей, которые на одной машине нарушили одно и то же правило   два и более раз. При этом учитывать все нарушения, независимо от того оплачены они или нет. Информацию отсортировать в алфавитном порядке, сначала по фамилии водителя, потом по номеру машины и, наконец, по нарушению.

```SQL
SELECT name, number_plate, violation
  FROM fine
 GROUP BY name, number_plate, violation
HAVING COUNT(violation) > 1
 ORDER BY name;
```
*Результат*
```
+---------------+--------------+----------------------------------+
| name          | number_plate | violation                        |
+---------------+--------------+----------------------------------+
| Абрамова К.А. | О111АВ       | Проезд на запрещающий сигнал     |
| Баранов П.Е.  | Р523ВТ       | Превышение скорости(от 40 до 60) |
+---------------+--------------+----------------------------------+
```
## Задание
В таблице fine увеличить в два раза сумму неоплаченных штрафов для отобранных на предыдущем шаге записей. 

**Запрос**
```SQL
UPDATE fine,
       (SELECT NAME, number_plate, violation
  			 FROM fine
 		   GROUP BY NAME, number_plate, violation
		  HAVING COUNT(violation) > 1
		  ) AS query_in
   SET fine.sum_fine = fine.sum_fine * 2
 WHERE fine.date_payment IS NULL AND
       fine.name = query_in.name AND
		 fine.number_plate = query_in.number_plate AND
		 fine.violation = query_in.violation; 	
```
*Результат*
```
Query result:
+---------------+--------------+----------------------------------+----------+------------------+--------------+
| name          | number_plate | violation                        | sum_fine | date_violation   | date_payment |
+---------------+--------------+----------------------------------+----------+------------------+--------------+
| Баранов П.Е.  | Р523ВТ       | Превышение скорости(от 40 до 60) | 500.00   | 2020-01-12       | 2020-01-17   |
| Абрамова К.А. | О111АВ       | Проезд на запрещающий сигнал     | 1000.00  | 2020-01-14       | 2020-02-27   |
| Яковлев Г.Р.  | Т330ТТ       | Превышение скорости(от 20 до 40) | 500.00   | 2020-01-23       | 2020-02-23   |
| Яковлев Г.Р.  | М701АА       | Превышение скорости(от 20 до 40) | 500.00   | 2020-01-12       | NULL        |
| Колесов С.П.  | К892АХ       | Превышение скорости(от 20 до 40) | 500.00   | 2020-02-01       | NULL         |
| Баранов П.Е.  | Р523ВТ       | Превышение скорости(от 40 до 60) | 2000.00  | 2020-02-14       | NULL         |
| Абрамова К.А. | О111АВ       | Проезд на запрещающий сигнал     | 2000.00  | 2020-02-23       | NULL         |
| Яковлев Г.Р.  | Т330ТТ       | Проезд на запрещающий сигнал     | 1000.00  | 2020-03-03       | NULL         |
+---------------+--------------+----------------------------------+----------+------------------+--------------+
```