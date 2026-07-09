# Write your MySQL query statement below
SELECT a1.machine_id,
ROUND(AVG(a1.timestamp - a2.timestamp), 3) as processing_time

FROM Activity as a1, Activity as a2
WHERE a1.machine_id = a2.machine_id AND a1.process_id = a2.process_id AND a1.activity_type='end' AND a2.activity_type='start'
Group by machine_id