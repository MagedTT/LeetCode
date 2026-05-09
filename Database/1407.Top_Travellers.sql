-- Problem Link: https://leetcode.com/problems/top-travellers/

WITH CTE_Total_distance AS
(
    SELECT
        user_id,
        SUM(distance) AS travelled_distance
    FROM Rides
    GROUP BY user_id
)
SELECT
    name,
    ISNULL(travelled_distance, 0) AS travelled_distance
FROM Users AS u
LEFT JOIN CTE_Total_distance AS r
    ON u.id = r.user_id
ORDER BY travelled_distance DESC, name ASC