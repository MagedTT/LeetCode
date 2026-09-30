Problem Link: https://leetcode.com/problems/game-play-analysis-iv/

WITH CTE1 AS
(
    SELECT
        player_id,
        event_date AS currentDate,
        DATEDIFF(DAY, FIRST_VALUE(event_date) OVER(PARTITION BY player_id ORDER BY event_date), event_date) AS Numerator
    FROM Activity
)
, CTE2 AS
(
    SELECT
        SUM(CASE WHEN Numerator = 1 THEN 1 ELSE 0 END) AS Numerator,
        COUNT(DISTINCT player_id) AS TotalPlayers
    FROM CTE1
)
SELECT
    ROUND(CAST(Numerator AS FLOAT) / TotalPlayers, 2) AS fraction
FROM CTE2
