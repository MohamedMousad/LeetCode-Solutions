# Write your MySQL query statement below
with res as (SELECT visited_on , sum(amount) as amount 
from customer group by visited_on)

select a.visited_on , sum(b.amount) as amount ,  round(sum(b.amount)/7 , 2) as average_amount
from res a , res b 
where (a.visited_on - INTERVAL 6 DAY) in (select visited_on from res) and DATEDIFF(a.visited_on , b.visited_on) <= 6 and DATEDIFF(a.visited_on , b.visited_on) >= 0
group by a.visited_on