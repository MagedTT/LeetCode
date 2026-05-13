-- Problem Link: https://leetcode.com/problems/primary-department-for-each-employee/

SELECT
    employee_id,
    department_id
FROM (
    SELECT
        employee_id,
        department_id,
        primary_flag,
        COUNT(1) OVER(PARTITION BY employee_id) AS rn
    FROM Employee
) AS t
WHERE (rn = 1 AND primary_flag = 'N') OR (primary_flag = 'Y' AND rn > 1)