-- Problem Link: https://leetcode.com/problems/classes-with-at-least-5-students/

SELECT
    class
FROM (
    SELECT
        class,
        COUNT(1) AS total
    FROM Courses
    GROUP BY class
) AS t
WHERE total >= 5;