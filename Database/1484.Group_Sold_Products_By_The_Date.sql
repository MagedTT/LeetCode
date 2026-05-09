-- Problem Link: https://leetcode.com/problems/group-sold-products-by-the-date/

WITH cte AS
(
    SELECT
        DISTINCT
        sell_date,
        product
    FROM Activities
)
SELECT
    sell_date,
    COUNT(product) AS num_sold,
    STRING_AGG(product, ',') AS products
FROM cte
GROUP BY sell_date
ORDER BY sell_date;