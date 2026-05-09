-- Problem Link: https://leetcode.com/problems/find-users-with-valid-e-mails/

SELECT
    user_id,
    name,
    mail
FROM Users
WHERE
    mail LIKE '[A-Za-z]%'
    AND LEFT(mail, LEN(mail) - 13) NOT LIKE '%[^A-Za-z0-9_.-]%'
    AND RIGHT(mail, 13) COLLATE Latin1_General_CS_AS = '@leetcode.com'