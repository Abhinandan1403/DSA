# Write your MySQL query statement below
SELECT Visits.customer_id, COUNT(*) as count_no_trans
FROM Visits
LEFT JOIN Transactions
ON Visits.visit_id = Transactions.visit_id
WHERE Transactions.transaction_id is NULL
Group by Visits.customer_id;