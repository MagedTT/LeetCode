-- Problem Link: https://leetcode.com/problems/find-users-with-high-token-usage/

SELECT
    user_id,
    COUNT(prompt) AS prompt_count,
    ROUND(AVG(tokens * 1.0), 2) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING COUNT(prompt) > 2 AND ROUND(AVG(tokens), 2) < MAX(tokens)
ORDER BY avg_tokens DESC, user_id ASC;