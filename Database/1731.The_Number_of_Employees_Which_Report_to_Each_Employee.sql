-- Problem Link: https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/

WITH CTE AS
(
    SELECT
        reports_to AS employee_id,
        COUNT(employee_id) AS reports_count,
        ROUND(AVG(CAST(age AS FLOAT)), 0) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
    HAVING (COUNT(employee_id) > 0)
)
SELECT
    CTE.employee_id,
    name,
    CTE.reports_count,
    CTE.average_age
FROM Employees
INNER JOIN CTE
ON Employees.employee_id = CTE.employee_id
ORDER BY CTE.employee_id;