# Write your MySQL query statement below
select 
    p.product_id as product_id, 
    Round(CASE WHEN p.product_id not in (SELECT distinct product_id FROM UnitsSold) THEN 0 ELSE sum(us.units*p.price) / sum(us.units) END, 2) as average_price 
from  Prices p  
LEFT JOIN 
    UnitsSold us  on us.purchase_date >= p.start_date and us.purchase_date <= p.end_date and us.product_id = p.product_id
GROUP BY p.product_id 