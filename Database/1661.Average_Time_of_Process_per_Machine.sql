-- Problem Link: https://leetcode.com/problems/average-time-of-process-per-machine/

SELECT
    machine_id,
    ROUND(
            SUM(
            CASE
                WHEN activity_type = 'end' THEN timestamp
                ELSE -1 * timestamp
            END
        ) / COUNT(DISTINCT process_id), 3
    ) AS processing_time
FROM Activity
GROUP BY machine_id;