# Intro_to_SQL

Для SQL пишется query, который используется как команда для загрузки необходимой информации с базы данных. Т.к. база данных может быть очень большой (несколько терабайт), и не все данные нужны, поэтому надо использовать такой способ, чтобы не загружать все данные. Для этого используется query --- список команд, для SQL. 

Пример: 

```
query = """
        SELECT id, title, owner_user_id
        FROM `bigquery-public-data.stackoverflow.posts_questions`
        WHERE tags LIKE '%bigquery%'
        """
```

Здесь, 
SELECT --- это названия столбцов, которые мы хотим загрузить. 
FROM --- это адрес или название базы данных
WHERE --- дополнительное условие для фильтрации данных, в нашем случае мы добавили LIKE, который позволяет искать данные в столбцах, которые содержат определенные значения. В нашем случае --- 'bigquery', % --- любое значение. 
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

Для этого используется команда INNER JOIN и ON. INNER JOIN --- дополнительная таблица, ON --- столбец, по которому таблицы объединяются. Надо иметь в виду, что у таблиц, должен быть совпадающий столбец.

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
