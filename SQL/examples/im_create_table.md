# Задание

Создать счет (таблицу buy_pay) на оплату заказа с номером 5, в который включить название книг, их автора, цену, количество заказанных книг и  стоимость. Последний столбец назвать Стоимость. Информацию в таблицу занести в отсортированном по названиям книг виде.

*Запрос*

```SQL
CREATE TABLE buy_pay AS
SELECT title, name_author, book.price, buy_book.amount, (book.price*buy_book.amount) AS Стоимость
  FROM 
       author
       INNER JOIN book     ON author.author_id = book.author_id
       INNER JOIN buy_book ON book.book_id = buy_book.book_id
 WHERE buy_book.buy_id = 5
 ORDER BY title;
SELECT * FROM buy_pay;
```

**Результат**
```
Affected rows: 2

Query result:
+---------------+----------------+--------+--------+-----------+
| title         | name_author    | price  | amount | Стоимость |
+---------------+----------------+--------+--------+-----------+
| Белая гвардия | Булгаков М.А.  | 540.50 | 1      | 540.50    |
| Лирика        | Пастернак Б.Л. | 518.99 | 2      | 1037.98   |
+---------------+----------------+--------+--------+-----------+
Affected rows: 2
```