# Write your MySQL query statement below
SELECT
    d.name as Department ,  
    e.name as Employee , 
    e.salary as Salary
FROM 
    Employee e join Department d on e.departmentId = d.id
WHERE 
    (d.id , salary) in 
(SELECT 
    d.id as id , 
    MAX(e.salary) as max_salary
FROM 
    Employee e join Department d on e.departmentId = d.id
GROUP BY 
    d.id)