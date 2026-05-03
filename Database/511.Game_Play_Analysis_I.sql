-- Problem Link: https://leetcode.com/problems/game-play-analysis-i/description/

-- SELECT
--     DISTINCT(player_id),
--     FIRST_VALUE(event_date) OVER(PARTITION BY player_id ORDER BY event_date) AS first_login
-- FROM Activity

SELECT
    player_id,
    event_date AS first_login
FROM (
    SELECT
        player_id,
        event_date,
        ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) AS ranking
    FROM Activity
) AS temp
WHERE ranking = 1