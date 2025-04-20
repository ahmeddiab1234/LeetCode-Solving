-- https://leetcode.com/problems/find-valid-emails/description/

/* Write your T-SQL query statement below */

select user_id, email from Users 
where 
len(email) - len(replace(email, '@', '')) = 1
and email like '%.com'
and left(email, charindex('@', email) - 1) not like '%[^a-zA-Z0-9_]%'
and substring(
        email,
        charindex('@', email) + 1, 
        len(email) - charindex('@', email) - 4
      ) not like '%[^a-zA-Z]%'
order by user_id asc;
