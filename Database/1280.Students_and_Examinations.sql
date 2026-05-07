-- Problem Link: https://leetcode.com/problems/students-and-examinations/description/

WITH cte1 AS
(
    SELECT
        student_id,
        subject_name,
        COUNT(1) AS total_count
    FROM Examinations
    GROUP BY student_id, subject_name
)
, cte2 AS
(
    SELECT
        student_id,
        student_name,
        subject_name
    FROM Students
    CROSS JOIN Subjects
)
SELECT
    cte2.student_id,
    cte2.student_name,
    cte2.subject_name,
    ISNULL(cte1.total_count, 0) AS attended_exams
FROM cte2
LEFT JOIN cte1
    ON cte1.student_id = cte2.student_id
    AND cte1.subject_name = cte2.subject_name
ORDER BY cte2.student_id, cte2.subject_name