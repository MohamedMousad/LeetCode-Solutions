# Write your MySQL query statement below
SELECT firstName , lastName  , city  , state from Person left Join Address on Person.personId = Address.personId;