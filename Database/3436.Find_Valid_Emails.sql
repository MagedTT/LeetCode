-- Problem Link: https://leetcode.com/problems/find-valid-emails/

SELECT
    user_id,
    email
    -- SUBSTRING(email, CHARINDEX('@', email) + 1, LEN(email) - CHARINDEX('@', email) - 4)
FROM Users
WHERE
    RIGHT(email, 4) = '.com'
    AND LEN(email) - LEN(REPLACE(email, '@', '')) = 1
    AND LEFT(email, ABS(CHARINDEX('@', email) - 1)) NOT LIKE '%[^A-Za-z0-9_]%'
    AND LEN(SUBSTRING(email, CHARINDEX('@', email) + 1, LEN(email) - CHARINDEX('@', email) - 4)) > 0
    AND SUBSTRING(email, CHARINDEX('@', email) + 1, LEN(email) - CHARINDEX('@', email) - 4) NOT LIKE '%[^A-Za-z]%'
ORDER BY user_id;