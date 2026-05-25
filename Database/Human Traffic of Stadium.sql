# Write your MySQL query statement below
select 
    s0.id as id , s0.visit_date as visit_date  , s0.people as people 
from 
    stadium s0
    LEFT JOIN stadium s1 on s0.id  = s1.id + 1
    LEFT JOIN stadium s2 on s0.id  = s2.id + 2
    LEFT JOIN stadium s3 on s0.id  = s3.id - 1
    LEFT JOIN stadium s4 on s0.id  = s4.id - 2
where 
    (s0.people >= 100 and s1.people is not null and s1.people >= 100 && s2.people is not null and s2.people >= 100)
    or 
    (s0.people >= 100 and s3.people is not null and s3.people >= 100 && s4.people is not null and s4.people >= 100)
    or
    (s0.people >= 100 and s1.people is not null and s1.people >= 100 && s3.people is not null and s3.people >= 100)
order by s0.visit_date 

