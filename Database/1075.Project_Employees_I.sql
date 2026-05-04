-- Problem Link: https://leetcode.com/problems/project-employees-i/description/

SELECT
    project_id,
    ROUND(AVG(CAST(experience_years AS DECIMAL)), 2) AS average_years
FROM (
    SELECT
        project_id,
        Employee.employee_id,
        experience_years
    FROM Project
    INNER JOIN Employee
        ON Project.employee_id = Employee.employee_id
) AS t
GROUP BY project_id;