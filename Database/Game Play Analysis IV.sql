# Write your MySQL query statement below
-- SELECT ROUND( SELECT player_id from Activity where event_date - INTERVAL 1 DAY =  min(event_date)) / 
--             (SELECT COUNT(distinct player_id) FROM Activity) , 2) AS fraction;
SELECT 
ROUND((SELECT count(a1.player_id) as cnt FROM Activity a1 WHERE 
(a1.player_id , a1.event_date - INTERVAL 1 DAY ) IN (SELECT player_id , min(event_date) from Activity GROUP BY player_id)) / 
(SELECT COUNT(distinct player_id) FROM Activity) , 2) AS fraction