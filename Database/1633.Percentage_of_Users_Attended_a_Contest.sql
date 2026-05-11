-- Problem Link: https://leetcode.com/problems/percentage-of-users-attended-a-contest/

SELECT
    contest_id,
    ROUND(CAST(COUNT(user_id) AS FLoat) / (SELECT COUNT(1) AS total FROM Users) * 100, 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;