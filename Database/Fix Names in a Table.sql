# Write your MySQL query statement below
select user_id , CONCAT(Upper(substring(name , 1 , 1)) ,  Lower(substring(name , 2))) as name from Users order by user_id;