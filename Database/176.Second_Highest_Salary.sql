-- Problem Link: https://leetcode.com/problems/second-highest-salary/

WITH cte AS
(
    SELECT
        MAX(Salary) AS Salary
    FROM Employee
)
SELECT
    MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT Salary FROM cte);