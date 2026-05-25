SELECT 
    ROUND(SUM(tiv_2016) , 2) as tiv_2016
FROM 
    Insurance 
WHERE
    tiv_2016 is not null and tiv_2015 is not null  and (pid in (select pid from Insurance group by lat , lon having COUNT(pid) = 1))
    and tiv_2015 in (select tiv_2015 from Insurance group by tiv_2015 having count(tiv_2015) >  1 )