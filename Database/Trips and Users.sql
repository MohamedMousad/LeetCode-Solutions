# Write your MySQL query statement below
Select
    request_at as Day , ROUND(SUM(CASE WHEN status like 'cancelled%' THEN 1 ELSE 0 END) /  COUNT(status) , 2) as 'Cancellation Rate'
from 
    Trips 
where 
    request_at >= "2013-10-01" and request_at <= '2013-10-03' 
    and client_id not in (select users_id from users where banned = 'Yes' )
    and driver_id not in (select users_id from users where banned = 'Yes' )
group by 
    request_at
