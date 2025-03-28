# Выборка данных, оператор LIKE

Оператор ```LIKE``` используется для сравнения строк. В отличие от операторов отношения равно (=) и не равно (<>), ```LIKE``` позволяет сравнивать строки не на полное совпадение (не совпадение), а в соответствии с шаблоном. Шаблон может включать **обычные символы** и **символы-шаблоны**. При сравнении с шаблоном, его обычные символы должны в точности совпадать с символами, указанными в строке. Символы-шаблоны могут совпадать с произвольными элементами символьной строки.

|Символ-шаблон|Описание|Пример|
|:---|:---|:---|
|%|Любая строка, содержащая ноль или более символов|SELECT * FROM book WHERE author LIKE '%М.%' выполняет поиск и выдает все книги, инициалы авторов которых содержат «М.»|
|- (подчеркивание)|Любой одиночный символ|SELECT * FROM book WHERE title LIKE 'Поэм_' выполняет поиск и выдает все книги, названия которых либо «Поэма», либо «Поэмы» и пр.|

**Пример 1**

Вывести названия книг, начинающихся с буквы «Б».

*Запрос:*
```SQL
SELECT title
  FROM book
 WHERE title LIKE 'Б%';
/* эквивалентное условие
title LIKE 'б%' */
```

Результат:
```
+-------------------+
| title             |
+-------------------+
| Белая гвардия     |
| Братья Карамазовы |
+-------------------+
```

Пример 2

Вывести название книг, состоящих ровно из 5 букв.

Запрос:
```SQL
SELECT title FROM book 
 WHERE title LIKE "_____"
```
Результат:
```
+-------+
| title |
+-------+
| Идиот |
| Поэмы |
+-------+
```

**Пояснение**
Для обозначения одного любого символа используется  "_", следовательно для обозначения 5 символов используется 5 подряд символов подчеркивания.


**Пример 3**

Вывести книги, название которых длиннее 5 символов:

Запрос:
```SQL
SELECT title FROM book
 WHERE title LIKE "______%";
/* эквивалентные условия
title LIKE "%______"
title LIKE "%______%" */
```
Результат:
```
+-----------------------+
| title                 |
+-----------------------+
| Мастер и Маргарита    |
| Белая гвардия         |
| Братья Карамазовы     |
| Стихотворения и поэмы |
| Дети полуночи         |
| Лирика                |
| Капитанская дочка     |
+-----------------------+
```
**Пояснение**  

Для того чтобы вывести названия, состоящие из любого количества символов после ```LIKE``` можно использовать шаблон "%", с помощью которого отбираются строки, состоящие из любого количества символов, в том числе и "пустые", поскольку % заменяет любое количество символов, в том числе и нулевое.

Чтобы указать, что в названии должен быть хотя бы один символ, можно использовать один из эквивалентных шаблонов:

* "_%" - сначала идет символ, а за ним любое количество символов;
* "%_" - сначала идет любое количество символов, а затем обязательный символ;
* "%_%" - сначала идет любое количество символов, потом обязательный символ, а за ним любое количество символов.

**Пример 4**

Вывести названия книг, которые содержат букву "и" как отдельное слово, если считать, что слова в названии отделяются друг от друга пробелами и не содержат знаков препинания.

 Запрос:
```SQL
SELECT title FROM book
 WHERE title LIKE "_% и _%" /*отбирает слово И внутри названия */
    OR title LIKE "и _%" /*отбирает слово И в начале названия */
    OR title LIKE "_% и" /*отбирает слово И в конце названия */
    OR title LIKE "и" /* отбирает название, состоящее из одного слова И */
```
Результат:
```
+-----------------------+
| title                 |
+-----------------------+
| Мастер и Маргарита    |
| Стихотворения и поэмы |
+-----------------------+
```

**Пояснение**
Слово "и" может располагаться в названии в следующих позициях (при условии, что слова отделяются друг от друга пробелами):

* в середине -  "_% и _%" - сначала идет любое количество символов (один обязательный), потом обязательный пробел, а за ним "и", снова обязательный пробел, и наконец любое количество символов (один обязательный);
* в начале - "и _%" - сначала идет "и", обязательный пробел и любое количество символов (один обязательный);
* в конце - "_% и" - сначала идет любое количество символов, затем обязательный пробел и буква "и":
* одно слово в названии - "и".

Вместо "_%" можно использовать эквивалентные шаблоны "%_" и "%_%" .

В качестве обязательного символа ( "_"), может быть и пробел, но, к сожалению, шаблоны для ```LIKE``` не позволяют исключить какой-то символ. Это можно сделать только с помощью регулярных выражений

**Пример 5**

Вывести названия книг, которые состоят ровно из одного слова, если считать, что слова в названии отделяются друг от друга пробелами .

*Запрос:*
```SQL
SELECT title FROM book
 WHERE title  NOT LIKE "% %";    
```

*Результат:*
```
+--------+
| title  |
+--------+
| Идиот  |
| Лирика |
| Поэмы  |
+--------+
```

## Задание

Вывести название и автора тех книг, название которых состоит из двух и более слов, а инициалы автора содержат букву «С». Считать, что в названии слова отделяются друг от друга пробелами и не содержат знаков препинания, между фамилией автора и инициалами обязателен пробел, инициалы записываются без пробела в формате: буква, точка, буква, точка. Информацию отсортировать по названию книги в алфавитном порядке.

**Решение:**
```SQL
SELECT title, author
  FROM book
 WHERE title   LIKE "_% _%"   
   AND (author LIKE "_% С.%"
    OR author  LIKE "_% %.С.")
 ORDER BY title ASC 
```

Результат:
```
+-----------------------+-------------+
| title                 | author      |
+-----------------------+-------------+
| Капитанская дочка     | Пушкин А.С. |
| Стихотворения и поэмы | Есенин С.А. |
+-----------------------+-------------+
```
