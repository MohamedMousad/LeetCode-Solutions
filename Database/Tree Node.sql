# Write your MySQL query statement below

Select id , 
(CASE WHEN T2.p_id is null THEN "Root" 
      WHEN T2.id not in (SELECT p_id from Tree T1 where p_id is not null) THEN "Leaf" 
      ELSE "Inner" END) as type from Tree  T2;