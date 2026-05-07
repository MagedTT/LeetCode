-- Problem Link: https://leetcode.com/problems/queries-quality-and-percentage/

SELECT
    query_name,
    ROUND(AVG((CAST(rating AS FLOAT) / position)), 2) AS quality,
    ROUND(CAST(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) AS FLOAT) / COUNT(1) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name