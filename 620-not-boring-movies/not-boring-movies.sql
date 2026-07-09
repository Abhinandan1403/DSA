# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE Cinema.description != 'boring' AND Cinema.id&1 = 1
ORDER BY rating DESC;