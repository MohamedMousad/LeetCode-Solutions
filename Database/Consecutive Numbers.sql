# Write your MySQL query statement below
with res as (
    select 
        num as first , 
        lag(num , 1 ) OVER (ORDER BY id ) as previous ,  
        lag(num , 2 ) OVER (ORDER BY id ) as last 
        from Logs)

select distinct first as ConsecutiveNums from res where 
        first = previous and last = first;