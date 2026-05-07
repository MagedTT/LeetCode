-- Problem Link: https://leetcode.com/problems/average-selling-price/

WITH CTE_Total_Price_Per_Product AS
(
    SELECT
        p.product_id,
        SUM(price * ISNULL(units, 0)) AS TotalPrice
    FROM Prices AS p
    LEFT JOIN UnitsSold AS us
        ON p.product_id = us.product_id
    WHERE us.purchase_date IS NULL OR us.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY p.product_id
)
, CTE_Total_Units AS
(
    SELECT
        product_id,
        SUM(units) AS TotalUnits
    FROM UnitsSold
    GROUP BY product_id
)
SELECT
    cte1.product_id,
    CASE
        WHEN cte2.product_id IS NULL THEN 0
        ELSE ROUND(CAST(TotalPrice AS FLOAT) / TotalUnits, 2)
    END AS average_price
FROM CTE_Total_Price_Per_product AS cte1
LEFT JOIN CTE_Total_Units AS cte2
    ON cte1.product_id = cte2.product_id;

-- SELECT
--     p.product_id,
--     ISNULL(ROUND(SUM(price * units) / CAST(SUM(units) AS FLOAT), 2), 0) AS average_price
-- FROM Prices AS p
-- LEFT JOIN UnitsSold AS us
--     ON p.product_id = us.product_id
-- AND us.purchase_date BETWEEN p.start_date AND p.end_date
-- GROUP BY p.product_id;
