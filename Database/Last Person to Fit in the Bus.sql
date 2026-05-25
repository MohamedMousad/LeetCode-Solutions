# Write your MySQL query statement below
with res as(select person_name , sum(weight) OVER(ORDER BY turn) as total from queue )

select person_name from res where total <= 1000 order by total desc limit 1 