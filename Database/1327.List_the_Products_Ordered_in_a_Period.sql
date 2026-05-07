-- Problem Link: https://leetcode.com/problems/list-the-products-ordered-in-a-period/description/

SELECT
    product_name,
    unit
FROM Products
INNER JOIN (
    SELECT
        product_id,
        SUM(unit) AS unit
    FROM Orders
    WHERE YEAR(order_date) = 2020 AND MONTH(order_date) = 2
    GROUP BY product_id
    HAVING SUM(unit) >= 100
) AS t
    ON Products.product_id = t.product_id