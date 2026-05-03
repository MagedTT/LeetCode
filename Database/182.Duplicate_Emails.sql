-- Problem Link: https://leetcode.com/problems/duplicate-emails/description/

SELECT
    DISTINCT(email)
FROM (
    SELECT
        email,
        ROW_NUMBER() OVER(PARTITION BY email ORDER BY email) AS email_row_number
    FROM Person
) AS t WHERE email_row_number > 1;