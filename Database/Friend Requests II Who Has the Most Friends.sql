# Write your MySQL query statement below
with res as(SELECT  
    requester_id as f , accepter_id as s 
from 
    RequestAccepted 
union
SELECT  
    accepter_id as f , requester_id as s 
from 
    RequestAccepted )
select 
    f as id , COUNT(f) as num
from 
    res
group by 
    id
ORDER BY num DESC
LIMIT 1