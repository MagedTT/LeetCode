-- Problem Link: https://leetcode.com/problems/product-sales-analysis-i/description/

SELECT
    product_name,
    year,
    price
FROM Sales
INNER JOIN Product
    ON Sales.product_id = Product.product_id