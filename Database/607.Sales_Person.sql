-- Problem Link: https://leetcode.com/problems/sales-person/description/

SELECT
    name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT
        sp.sales_id
    FROM SalesPerson AS sp
    INNER JOIN Orders AS o
    ON sp.sales_id = o.sales_id
    INNER JOIN Company AS c
    ON o.com_id = c.com_id
    WHERE c.name = 'RED'
)