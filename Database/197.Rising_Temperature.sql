-- Problem Link: https://leetcode.com/problems/rising-temperature/description/

SELECT
    id
FROM (
    SELECT
        id,
        temperature AS CurrentTemperature,
        LAG(temperature) OVER(ORDER BY recordDate) AS PreviousTemperature,
        DATEDIFF(DAY, LAG(recordDate) OVER(ORDER BY recordDate), recordDate) AS DifferenceInDays
    FROM Weather
) AS t
WHERE DifferenceInDays = 1 AND CurrentTemperature > PreviousTemperature;