-- Problem Link: https://leetcode.com/problems/calculate-special-bonus/

SELECT
    employee_id,
    CASE
        WHEN LEFT(name, 1) <> 'm' AND employee_id % 2 = 1 THEN salary
        ELSE 0
    END AS bonus
FROM Employees
ORDER BY employee_id;