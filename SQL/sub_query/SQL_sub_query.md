## Вложенный запрос, возвращающий одно значение

Вложенный запрос, возвращающий одно значение, может использоваться в условии отбора записей WHERE как обычное значение совместно с операциями =, <>, >=, <=, >, <.

**Пример**

Вывести информацию о самых дешевых книгах, хранящихся на складе.

Для реализации этого запроса нам необходимо получить минимальную цену из столбца price таблицы book, а затем вывести информацию о тех книгах, цена которых  равна минимальной. Первая часть  – поиск  минимума – реализуется вложенным запросом.

*Запрос:*

```SQL
SELECT title, author, price, amount
  FROM book
 WHERE price = (
         SELECT MIN(price) 
           FROM book
      );
```

*Результат:*
```
+-------+------------------+--------+--------+
| title | author           | price  | amount |
+-------+------------------+--------+--------+
| Идиот | Достоевский Ф.М. | 460.00 | 10     |
+-------+------------------+--------+--------+
```

Вложенный запрос определяет минимальную цену книг во всей таблице (это 460.00), а затем в основном запросе для каждой записи проверяется, равна ли цена минимальному значению, если равна, информация о книге включается в результирующую таблицу запроса.

Рекомендация. При использовании вложенного запроса рекомендуется сначала проверить, правильно ли он работает (занести текст запроса в окно кода и нажать черную кнопку Запустить), если выдается верный результат – использовать код в качестве вложенного запроса.

## Задание

Вывести информацию (автора, название и цену) о  книгах, цены которых меньше или равны средней цене книг на складе. Информацию вывести в отсортированном по убыванию цены виде. Среднее вычислить как среднее по цене книги.

**Решение**
```SQL
SELECT author, title, price
  FROM book
 WHERE price <= (
              SELECT ROUND(AVG(price), 2)
                FROM book             
             )
 ORDER BY price DESC;
```

**Результат**
```
+------------------+---------------+--------+
| author           | title         | price  |
+------------------+---------------+--------+
| Булгаков М.А.    | Белая гвардия | 540.50 |
| Достоевский Ф.М. | Игрок         | 480.50 |
| Достоевский Ф.М. | Идиот         | 460.00 |
+------------------+---------------+--------+
```

# Использование вложенного запроса в выражении

Вложенный запрос, возвращающий одно значение, может использоваться в выражениях как обычный операнд, например, к нему можно что-то прибавить, вычесть и пр.

Пример

Вывести информацию о книгах, количество экземпляров которых отличается от среднего количества экземпляров книг на складе более чем на 3. То есть нужно вывести и те книги, количество экземпляров которых меньше среднего на 3, или больше среднего на 3.

Запрос:
```SQL
SELECT title, author, amount 
  FROM book
 WHERE ABS(amount - (SELECT AVG(amount) FROM book)) >3;
```
Результат:
```
+-----------------------+------------------+--------+
| title                 | author           | amount |
+-----------------------+------------------+--------+
| Мастер и Маргарита    | Булгаков М.А.    | 3      |
| Братья Карамазовы     | Достоевский Ф.М. | 3      |
| Стихотворения и поэмы | Есенин С.А.      | 15     |
+-----------------------+------------------+--------+
```

**Задание**

Вывести информацию (автора, название и цену) о тех книгах, цены которых превышают минимальную цену книги на складе не более чем на 150 рублей в отсортированном по возрастанию цены виде.


**Решение**
```SQL
SELECT author, title, price
  FROM book
 WHERE ABS(price - (SELECT MIN(price) FROM book)) <= 150
 ORDER BY price ASC;
```

*Результат*
```
+------------------+----------------+--------+
| author           | title          | price  |
+------------------+----------------+--------+
| Достоевский Ф.М. | Идиот          | 460.00 |
| Достоевский Ф.М. | Игрок          | 480.50 |
| Булгаков М.А.    | Белая гвардия  | 540.50 |
| Пушкин А.С.      | Евгений Онегин | 610.00 |
+------------------+----------------+--------+
```

# Вложенный запрос, оператор IN

Вложенный запрос может возвращать несколько значений одного столбца.  Тогда его можно использовать в разделе WHERE совместно с оператором IN.

```WHERE имя_столбца IN (вложенный запрос, возвращающий один столбец)```

Оператор IN определяет, совпадает ли значение столбца с одним из значений, содержащихся во вложенном запросе. При этом логическое выражение после WHERE получает значение истина. Оператор NOT IN выполняет обратное действие – выражение истинно, если значение столбца не содержится во вложенном запросе.

*Пример*

Вывести информацию о книгах тех авторов, общее количество экземпляров книг которых не менее 12.

*Запрос:*
```SQL
SELECT title, author, amount, price
  FROM book
 WHERE author IN (
        SELECT author 
          FROM book 
         GROUP BY author 
        HAVING SUM(amount) >= 12
      );
```

*Результат:*
```
+-----------------------+------------------+--------+--------+
| title                 | author           | amount | price  |
+-----------------------+------------------+--------+--------+
| Идиот                 | Достоевский Ф.М. | 10     | 460.00 |
| Братья Карамазовы     | Достоевский Ф.М. | 3      | 799.01 |
| Игрок                 | Достоевский Ф.М. | 10     | 480.50 |
| Стихотворения и поэмы | Есенин С.А.      | 15     | 650.00 |
+-----------------------+------------------+--------+--------+
```

Вложенный запрос отбирает двух авторов (Достоевского и Есенина). А в основном запросе для каждой записи таблицы book  проверяется, входит ли автор книги в отобранный список, если входит - информация о книге включается в запрос.
Задание

Вывести информацию (автора, книгу и количество) о тех книгах, количество экземпляров которых в таблице book не дублируется.


## Задание

Вывести информацию (автора, книгу и количество) о тех книгах, количество экземпляров которых в таблице book не дублируется.
Пояснение к заданию

В таблице ```book``` в столбце ```amount``` хранится количество экземпляров каждой книги:
```
+-----------------------+--------+
| title                 | amount |
+-----------------------+--------+
| Мастер и Маргарита    | 3      |
| Белая гвардия         | 5      |
| Идиот                 | 10     |
| Братья Карамазовы     | 3      |
| Игрок                 | 10     |
| Стихотворения и поэмы | 15     |
+-----------------------+--------+
```

В соответствии с этой таблицей:

* количество экземпляров книг "Мастер и Маргарита" и "Братья Карамазовы" одинаково и равно 3 (так как число 3 встречается в таблице два раза, книги с таким количеством не подходят под условие);
* количество экземпляров книг "Идиот" и "Игрок" тоже одинаково и равно 10 (не подходят под условие);
* количество экземпляров книги "Белая гвардия равно" 5, при этом в таблице нет других книг, количество экземпляров которых равно 5, следовательно, эта книга подходит под условие задачи (так как количество экземпляров 5 в таблице не дублируется);
* количество экземпляров книги "Стихотворение и поэмы"  - 15, в таблице нет других книг, количество экземпляров которых тоже равно 15, следовательно, и эта книга подходит под условие.

Таким образом, необходимо вывести те строки таблицы, у которых числа в столбце amount не повторяются.

**Решение**
```SQL
SELECT author, title, amount
  FROM book
 WHERE amount IN (
                SELECT amount
                  FROM book
                 GROUP BY amount
                HAVING count(amount)=1);
```

*Результат*
```
+---------------+-----------------------+--------+
| author        | title                 | amount |
+---------------+-----------------------+--------+
| Булгаков М.А. | Белая гвардия         | 5      |
| Есенин С.А.   | Стихотворения и поэмы | 15     |
+---------------+-----------------------+--------+
```