-- Problem Link: https://leetcode.com/problems/confirmation-rate/

SELECT
    s.user_id,
    ROUND(CAST(SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) AS FLOAT) / COUNT(1), 2) AS confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c
ON s.user_id = c.user_id
GROUP BY s.user_id;