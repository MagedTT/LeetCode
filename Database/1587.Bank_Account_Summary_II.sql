-- Problem Link: https://leetcode.com/problems/bank-account-summary-ii/

SELECT
    name,
    SUM(amount) AS balance
FROM Users AS u
INNER JOIN Transactions AS t
    ON u.account = t.account
GROUP BY name
HAVING SUM(amount) > 10000