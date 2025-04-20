-- https://leetcode.com/problems/duplicate-emails/description/

/* Write your T-SQL query statement below */

SELECT email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;
