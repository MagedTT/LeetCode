-- Problem Link: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/

SELECT
    TOP 1 customer_number
FROM (
    SELECT
        customer_number,
        COUNT(1) AS TotalOrders
    FROM Orders
    GROUP BY customer_number
) AS t
ORDER BY TotalOrders DESC