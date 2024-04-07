# Задание

Для каждой отдельной книги необходимо вывести информацию о количестве проданных экземпляров и их стоимости за 2020 и 2019 год . Вычисляемые столбцы назвать Количество и Сумма. Информацию отсортировать по убыванию стоимости.

**Использовать вложенный запрос**

Запросы с UNION можно использовать как вложенные, это позволяет обрабатывать данные из объединенных запросов совместно.

Пример

Вывести клиентов, которые делали покупки в прошлом году, но не делали в этом. А также новых клиентов, которые делали заказы только в текущем году. Информацию отсортировать по возрастанию лет.

Шаг 1. Отберем клиентов прошлого года, указав дату самого раннего заказа, а также клиентов этого года, указав для них самую раннюю дату оплаты заказа.

Запрос
```SQL
SELECT name_client, MIN(date_payment) AS first_payment
FROM
    buy_archive
    INNER JOIN client USING(client_id)
GROUP BY  name_client
UNION
SELECT name_client, MIN(date_step_end)
FROM
    buy
    INNER JOIN client USING(client_id)
    INNER JOIN buy_step USING(buy_id)
GROUP BY name_client
```
Результат:
```
+-----------------+---------------+
| name_client     | first_payment |
+-----------------+---------------+
| Абрамова Катя   | 2019-02-10    |
| Баранов Павел   | 2019-02-21    |
| Яковлева Галина | 2019-03-05    |
| Абрамова Катя   | 2020-03-05    |
| Баранов Павел   | 2020-02-20    |
| Семенонов Иван  | 2020-02-28    |
+-----------------+---------------+
```
Как видно из таблицы, некоторые клиенты делали покупки как в прошлом, так и в этом году. Они встречаются в таблице 2 раза.

Шаг 2. Оставим только тех клиентов, которые встречаются в полученной таблице один раз, для этого используем предыдущий запрос как вложенный.

Запрос:
```SQL
SELECT name_client, MIN(YEAR(first_payment)) AS Год
FROM
  (
   SELECT name_client, MIN(date_payment) AS first_payment
   FROM
       buy_archive
       INNER JOIN client USING(client_id)
   GROUP BY  name_client
   UNION
   SELECT name_client, MIN(date_step_end)
   FROM
       buy
       INNER JOIN client USING(client_id)
       INNER JOIN buy_step USING (buy_id)
   GROUP BY name_client
  ) query_in
GROUP BY name_client
HAVING COUNT(*) = 1
ORDER BY 2
```
Результат:
```
+-----------------+------+
| name_client     | Год  |
+-----------------+------+
| Яковлева Галина | 2019 |
| Семенонов Иван  | 2020 |
+-----------------+------+
```

*Запрос*
```SQL
SELECT title, SUM(am) AS Количество, SUM(revenue) AS Сумма
  FROM
      (

        SELECT title, SUM(buy_archive.amount) AS am,
               SUM(buy_archive.amount*buy_archive.price) AS revenue
          FROM
               buy_archive
               INNER JOIN book USING(book_id)
         GROUP BY title
         UNION ALL
        SELECT title, SUM(buy_book.amount) AS am,
               SUM(buy_book.amount*book.price) AS revenue
          FROM
               book
               INNER JOIN buy_book USING(book_id)
               INNER JOIN buy USING(buy_id) 
               INNER JOIN buy_step USING(buy_id)
               INNER JOIN step USING(step_id)                  
         WHERE date_step_end IS NOT Null and name_step = "Оплата"
         GROUP BY title
         ORDER BY title
       ) query_in
 GROUP BY title
 ORDER BY Сумма DESC
```

**Результат**
```
Query result:
+-----------------------+------------+---------+
| title                 | Количество | Сумма   |
+-----------------------+------------+---------+
| Братья Карамазовы     | 8          | 6247.20 |
| Мастер и Маргарита    | 6          | 4024.38 |
| Идиот                 | 5          | 2281.80 |
| Белая гвардия         | 3          | 1581.10 |
| Черный человек        | 2          | 1140.40 |
| Лирика                | 2          | 1037.98 |
| Игрок                 | 2          | 961.80  |
| Стихотворения и поэмы | 1          | 650.00  |
+-----------------------+------------+---------+
Affected rows: 8
```
