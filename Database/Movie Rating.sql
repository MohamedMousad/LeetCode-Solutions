WITH first AS (
    SELECT
        u.name,
        COUNT(mr.rating) AS cnt
    FROM
        Users u
    INNER JOIN 
        MovieRating mr ON u.user_id = mr.user_id 
    GROUP BY
        u.name
    ORDER BY
        cnt DESC,
        u.name ASC
    LIMIT 1
),
film AS (
    SELECT
        m.title,
        AVG(mr.rating) AS av_rate
    FROM
        Movies m
    INNER JOIN
        MovieRating mr ON mr.movie_id = m.movie_id 
        AND DATE_FORMAT(mr.created_at, '%Y-%m') = '2020-02'
    GROUP BY
        m.title
    ORDER BY
        av_rate DESC, 
        m.title ASC 
    LIMIT 1
)
SELECT name AS results FROM first
UNION ALL
SELECT title AS results FROM film;