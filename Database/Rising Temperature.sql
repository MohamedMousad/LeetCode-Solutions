# Write your MySQL query statement below
select a.id from Weather a Join weather b  on a.recordDate  - interval 1 day = b.recordDate and a.temperature > b.temperature