-- Problem Link: https://leetcode.com/problems/count-salary-categories/

WITH CTE_Account_Categories AS
(
    SELECT
    (
        CASE
            WHEN income < 20000 THEN 1
            ELSE 0
        END
    ) AS LowSalary,
    (
        CASE
            WHEN 20000 <= income AND income <= 50000 THEN 1
            ELSE 0
        END
    ) AS AverageSalary,
    (
        CASE
            WHEN 50000 < income THEN 1
            ELSE 0
        END
    ) AS HighSalary
    FROM Accounts
)
SELECT
    'Low Salary' AS category,
    SUM(LowSalary) AS accounts_count
FROM CTE_Account_Categories
UNION ALL
SELECT
    'Average Salary' AS category,
    SUM(AverageSalary) AS accounts_count
FROM CTE_Account_Categories
UNION ALL
SELECT
    'High Salary' AS category,
    SUM(HighSalary) AS accounts_count
FROM CTE_Account_Categories;
