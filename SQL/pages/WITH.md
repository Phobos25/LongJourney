- абличное выражение определяется с помощью оператора** `WITH`** и является частью запроса. Его синтаксис:
- ```
  WITH имя_выражения (имя_1, имя_2,...)
  AS
    (
     SELECT столбец_1, столбец_2,
     FROM 
       ... 
     )
  SELECT ...
   FROM имя_выражения
   ...
  ```
- В табличном выражении определяется запрос, результат которого нужно использовать в основной части запроса после **SELECT**. При этом основной запрос может обратиться к столбцам результата табличного выражения через имена, заданные в заголовке **WITH**. При этом количество имен должно совпадать с количеством результирующих столбцов табличного выражения.
- В одном запросе может быть несколько табличных выражений. При этом в 
  каждом табличном выражении можно использовать все предшествующие ему 
  табличные выражения.
- В табличном выражении необязательно давать имена столбцам 
  результата. В этом случае в основном запросе можно использовать имена 
  столбцов, указанных после **SELECT** в 
  табличном выражении. При наличии одинаковых имен в нескольких табличных 
  выражениях необходимо использовать полное имя столбца (имя табличного 
  выражения, точка, имя столбца).
- **Пример**
- Для каждого шага вывести процент правильных решений. Информацию 
  упорядочить по возрастанию процента верных решений. Столбцы результата 
  назвать **Шаг** и **`Успешность`**, процент успешных решений округлить до целого.
  **Важно. **Только для этого задания для одного из шагов установлено, что все ответы пользователей - неверные.
-
- ### Задание 1
	- Исправить запрос примера так: для шагов, которые  не имеют 
	  неверных ответов,  указать 100 как процент успешных попыток, если же шаг
	   не имеет верных ответов, указать 0. Информацию отсортировать сначала по
	   возрастанию успешности, а затем по названию шага в алфавитном порядке.
	- ### Решение
	  collapsed:: true
		- ```SQL 
		  WITH get_count_correct (st_n_c, count_correct)
		    AS (
		      SELECT step_name, count(*)
		      FROM 
		          step 
		          INNER JOIN step_student USING (step_id)
		      WHERE result = "correct"
		      GROUP BY step_name
		      ), 
		      get_count_wrong (st_n_w, count_wrong)
		      AS (
		            SELECT step_name, count(*)
		              FROM 
		                   step 
		             INNER JOIN step_student USING (step_id)
		             WHERE result = "wrong"
		             GROUP BY step_name    
		       )
		  SELECT st_n_c AS Шаг, 
		         IFNULL(ROUND(count_correct/(count_correct + count_wrong)*100), 100) AS Успешность
		    FROM  
		         get_count_correct 
		    LEFT JOIN get_count_wrong ON st_n_c = st_n_w
		   UNION
		  SELECT st_n_w AS Шаг,
		         IFNULL(ROUND(count_correct / (count_correct + count_wrong) * 100), 0) AS Успешность
		    FROM  
		         get_count_correct 
		   RIGHT JOIN get_count_wrong ON st_n_c = st_n_w
		  ORDER BY 2, Шаг ASC; 
		  ```
	- Результат
	  collapsed:: true
		- ```
		  Query result:
		  +--------------------------------------------------------------------------+------------+
		  | Шаг                                                                      | Успешность |
		  +--------------------------------------------------------------------------+------------+
		  | Задание. Работа с архивной таблицей, оператор UNION, часть 1             | 0          |
		  | Выборка данных, оператор LIKE                                            | 19         |
		  | Вложенные запросы в операторах соединения                                | 32         |
		  | Задание. Вывести самый популярный жанр                                   | 33         |
		  | Запросы для нескольких таблиц с группировкой                             | 33         |
		  | Задание. Вывести заказы, доставленные с опозданием                       | 35         |
		  | Задание. Вывести информацию о движении каждого заказа                    | 36         |
		  | Запросы для нескольких таблиц со вложенными запросами                    | 36         |
		  | Задание. Вывести подробную информацию о каждом заказе                    | 37         |
		  | Выборка данных, вычисляемые столбцы, логические функции                  | 44         |
		  | Операция соединение, использование USING()                               | 45         |
		  | Перекрестное соединение CROSS JOIN                                       | 45         |
		  | Задание. Вывести города, в которых живут клиенты магазина                | 48         |
		  | Задание. Посчитать, сколько раз была заказана каждая книга               | 48         |
		  | Запросы на основе трех и более связанных таблиц                          | 49         |
		  | Выборка данных с сортировкой                                             | 53         |
		  | Внешнее соединение LEFT и RIGHT OUTER JOIN                               | 55         |
		  | Запросы на выборку из нескольких таблиц                                  | 58         |
		  | Выборка данных, вычисляемые столбцы, математические функции              | 59         |
		  | Задание. Вывести клиентов, которые заказывали книги определенного автора | 63         |
		  | Задание. Вывести информацию об оплате каждого заказа                     | 65         |
		  | Выборка данных, логические операции                                      | 67         |
		  | Проектирование концептуальной модели базы данных                         | 70         |
		  | Выборка данных, операторы BETWEEN, IN                                    | 72         |
		  | Выборка данных с созданием вычисляемого столбца                          | 74         |
		  | Выборка отдельных столбцов                                               | 76         |
		  | Соединение INNER JOIN                                                    | 78         |
		  | Выборка данных по условию                                                | 81         |
		  | Выборка отдельных столбцов и присвоение им новых имен                    | 84         |
		  | Выборка всех данных из таблицы                                           | 87         |
		  | Задание. Работа с архивной таблицей, оператор UNION, часть 2             | 100        |
		  | Построение логической схемы базы данных                                  | 100        |
		  +--------------------------------------------------------------------------+------------+
		  Affected rows: 32
		  ```
- ### Задание 2
	- Вычислить прогресс пользователей по курсу. Прогресс вычисляется
	  как отношение верно пройденных шагов к общему количеству шагов в 
	  процентах, округленное до целого. В нашей базе данные о решениях 
	  занесены не для всех шагов, поэтому общее количество шагов определить 
	  как количество различных шагов в таблице **`step_student`.**
	  Тем пользователям, которые прошли все шаги (прогресс = 100%) выдать 
	  "Сертификат с отличием". Тем, у кого прогресс больше или равен 80% - 
	  "Сертификат". Для остальных записей в столбце **Результат **задать пустую строку ("").
	- Информацию отсортировать по убыванию прогресса, затем по имени пользователя в алфавитном порядке.
	- ### Решение
	  collapsed:: true
		- ```SQL
		  SET @max_progress = (SELECT COUNT(DISTINCT step_id) FROM step_student);
		  
		    WITH student_progress(student_name, progress) 
		      AS (
		          SELECT student_name, COUNT(DISTINCT step_id)
		            FROM 
		                 student
		                 INNER JOIN step_student USING (student_id)
		           WHERE result = "correct"     
		           GROUP BY student_name
		         )
		  SELECT student_name AS Студент,
		         ROUND(progress/@max_progress * 100) AS Прогресс,
		         IF(ROUND(progress/@max_progress * 100) = 100, "Сертификат с отличием", 
		            IF(ROUND(progress/@max_progress * 100) > 80, "Сертификат", "")) AS Результат
		    FROM
		         student_progress 
		   ORDER BY 2 DESC, 1 ASC
		  
		  ```
	- Результат
	  collapsed:: true
		- ```
		  Affected rows: 0
		  
		  Query result:
		  +------------+----------+-----------------------+
		  | Студент    | Прогресс | Результат             |
		  +------------+----------+-----------------------+
		  | student_60 | 100      | Сертификат с отличием |
		  | student_15 | 94       | Сертификат            |
		  | student_18 | 94       | Сертификат            |
		  | student_27 | 94       | Сертификат            |
		  | student_30 | 94       | Сертификат            |
		  | student_31 | 94       | Сертификат            |
		  | student_36 | 94       | Сертификат            |
		  | student_39 | 94       | Сертификат            |
		  | student_4  | 94       | Сертификат            |
		  | student_43 | 94       | Сертификат            |
		  | student_44 | 94       | Сертификат            |
		  | student_46 | 94       | Сертификат            |
		  | student_49 | 94       | Сертификат            |
		  | student_51 | 94       | Сертификат            |
		  | student_53 | 94       | Сертификат            |
		  | student_59 | 91       | Сертификат            |
		  | student_9  | 91       | Сертификат            |
		  | student_23 | 88       | Сертификат            |
		  | student_50 | 84       | Сертификат            |
		  | student_20 | 78       |                       |
		  | student_24 | 78       |                       |
		  | student_52 | 63       |                       |
		  | student_56 | 63       |                       |
		  | student_34 | 59       |                       |
		  | student_40 | 59       |                       |
		  | student_11 | 50       |                       |
		  | student_48 | 50       |                       |
		  | student_42 | 47       |                       |
		  | student_61 | 44       |                       |
		  | student_13 | 41       |                       |
		  | student_26 | 41       |                       |
		  | student_1  | 34       |                       |
		  | student_10 | 34       |                       |
		  | student_12 | 34       |                       |
		  | student_14 | 34       |                       |
		  | student_19 | 34       |                       |
		  | student_2  | 34       |                       |
		  | student_21 | 34       |                       |
		  | student_22 | 34       |                       |
		  | student_25 | 34       |                       |
		  | student_28 | 34       |                       |
		  | student_3  | 34       |                       |
		  | student_32 | 34       |                       |
		  | student_35 | 34       |                       |
		  | student_37 | 34       |                       |
		  | student_41 | 34       |                       |
		  | student_45 | 34       |                       |
		  | student_54 | 34       |                       |
		  | student_55 | 34       |                       |
		  | student_57 | 34       |                       |
		  | student_6  | 34       |                       |
		  | student_62 | 34       |                       |
		  | student_7  | 34       |                       |
		  | student_8  | 34       |                       |
		  | student_17 | 31       |                       |
		  | student_33 | 31       |                       |
		  | student_38 | 31       |                       |
		  | student_58 | 31       |                       |
		  | student_64 | 31       |                       |
		  | student_16 | 28       |                       |
		  | student_5  | 28       |                       |
		  | student_63 | 28       |                       |
		  | student_29 | 25       |                       |
		  | student_47 | 25       |                       |
		  +------------+----------+-----------------------+
		  Affected rows: 64
		  ```