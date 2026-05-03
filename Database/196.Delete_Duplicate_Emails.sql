-- Problem Link: https://leetcode.com/problems/delete-duplicate-emails/description/

WITH CTE_Duplicate_Emails AS
(
    SELECT
        ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) AS email_row_number
    FROM Person
)
DELETE FROM CTE_Duplicate_Emails WHERE email_row_number > 1

-- DELETE FROM Person WHERE Id IN (
--     SELECT
--         id
--     FROM (
--         SELECT
--             id,
--             ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) AS repeated_email_id
--         FROM Person
--     ) AS t
--     WHERE repeated_email_id > 1
-- )