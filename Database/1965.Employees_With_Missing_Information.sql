-- Problem Link: https://leetcode.com/problems/employees-with-missing-information/

SELECT
    ISNULL(e.employee_id, s.employee_id) AS employee_id
FROM Employees AS e
FULL JOIN Salaries AS s
    ON e.employee_id = s.employee_id
WHERE e.name IS NULL OR s.salary IS NULL
ORDER BY ISNULL(e.employee_id, s.employee_id);