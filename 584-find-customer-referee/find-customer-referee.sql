# Write your MySQL query statement below
-- SELECT name FROM Customer WHERE referee_id IS null OR referee_id <> 2 ;

SELECT name
FROM Customer
WHERE COALESCE(referee_id, 0) != 2;