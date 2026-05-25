# Write your MySQL query statement below
with res as (select 
                d.name as Department , 
                e.name as Employee , 
                e.Salary as Salary  , 
                DENSE_RANK() OVER(PARTITION BY d.id ORDER BY e.salary DESC) AS num
            FROM 
                Employee e INNER JOIN Department d on d.id = e.departmentId
            ) 
select 
    Department , 
    Employee , 
    Salary 
FROM 
    res
WHERE 
    num <= 3;


