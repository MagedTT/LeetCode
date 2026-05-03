-- Problem Link: https://leetcode.com/problems/employees-earning-more-than-their-managers/description/

SELECT
    e.name AS Employee
FROM Employee AS e
INNER JOIN Employee AS m
ON e.managerId = m.id
WHERE e.salary > m.salary;