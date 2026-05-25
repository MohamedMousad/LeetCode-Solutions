# Write your MySQL query statement below
select p1.product_id as product_id , new_price as price 
from Products p1 where( p1.product_id , p1.change_date ) IN
(SELECT p2.product_id, MAX(p2.change_date) as mx_date
    FROM Products p2
    WHERE p2.change_date <= '2019-08-16'
    GROUP BY p2.product_id)
union
SELECT product_id, 10 as price
    FROM Products
    GROUP BY product_id
    having MIN(change_date) > '2019-08-16'
