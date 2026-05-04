-- Problem Link: https://leetcode.com/problems/sales-analysis-iii/description/

SELECT
    p.product_id,
    p.product_name
FROM Product p
JOIN Sales s
    ON p.product_id = s.product_id
WHERE
    YEAR(s.sale_date) = 2019
    AND DATEPART(QUARTER, s.sale_date) = 1
    AND p.product_id NOT IN (
        SELECT product_id
        FROM Sales
        WHERE NOT (
            YEAR(sale_date) = 2019
            AND DATEPART(QUARTER, sale_date) = 1
        )
    )
GROUP BY p.product_id, p.product_name