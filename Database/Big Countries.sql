# Write your MySQL query statement below
select w.name , w.population , w.area from World as w where w.area >= 3e6 or w.population >= 25e6