-- Problem Link: https://leetcode.com/problems/find-products-with-valid-serial-numbers/

SELECT
    *
FROM Products
WHERE
    description COLLATE Latin1_General_CS_AS LIKE '% SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9] %'
    OR description COLLATE Latin1_General_CS_AS LIKE '% SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]'
    OR description COLLATE Latin1_General_CS_AS LIKE 'SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9] %'
    OR description COLLATE Latin1_General_CS_AS LIKE 'SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]'
ORDER BY product_id ASC;