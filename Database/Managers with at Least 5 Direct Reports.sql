# Write your MySQL query statement below
 Select 
    name 
from 
    Employee 
where 
    id in (SELECT managerId from Employee group by managerId having COUNT(managerId) >= 5)