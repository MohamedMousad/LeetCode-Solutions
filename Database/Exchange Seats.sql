SELECT 
    id, 
    CASE 
        WHEN id % 2 = 0 THEN LAG(student) OVER (ORDER BY id)
        WHEN id = COUNT(*) OVER() THEN student
        ELSE LEAD(student) OVER (ORDER BY id) 
    END AS student
from 
    SEAT;