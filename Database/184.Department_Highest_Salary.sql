-- Problem Link: https://leetcode.com/problems/department-highest-salary/

WITH CTE_Department_Highest_Salary AS
(
    SELECT
        departmentId,
        MAX(salary) AS maxSalary
    FROM Employee
    GROUP BY departmentId
)
SELECT
    d.name AS Department,
    e.name AS Employee,
    cte.maxSalary AS Salary
FROM CTE_Department_Highest_Salary AS cte
INNER JOIN Department AS d
ON cte.departmentId = d.id
INNER JOIN Employee AS e
ON d.id = e.departmentId
WHERE e.salary = cte.maxSalary;
