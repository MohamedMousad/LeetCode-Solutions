# Write your MySQL query statement below
select activity_date as day , COUNT(distinct user_id) as active_users from Activity group by day having day >=  '2019-06-28' and day <= '2019-07-27'