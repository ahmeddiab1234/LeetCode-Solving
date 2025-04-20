-- https://leetcode.com/problems/combine-two-tables/description/

/* Write your T-SQL query statement below */
select firstName, lastName, city, state 
from Person p left join Address a 
on p.personID=a.personID;