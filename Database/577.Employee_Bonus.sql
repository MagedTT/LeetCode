-- Problem Link: https://leetcode.com/problems/employee-bonus/description/

SELECT
    name,
    bonus
FROM Employee AS e
LEFT JOIN Bonus AS b
ON e.empId = b.empId
WHERE b.empId IS NULL OR b.bonus < 1000;