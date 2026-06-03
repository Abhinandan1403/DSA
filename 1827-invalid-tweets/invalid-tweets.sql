-- # Write your MySQL query statement below

SELECT tweet_id from Tweets WHERE LENGTH(content)>15;


-- SELECT tweet_id
-- FROM Tweets
-- WHERE LENGTH(content) - LENGTH(REPLACE(content, ' ', '')) + 1 > 2;