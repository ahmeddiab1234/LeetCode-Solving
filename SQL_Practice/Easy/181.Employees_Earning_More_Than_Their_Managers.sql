-- https://leetcode.com/problems/employees-earning-more-than-their-managers/description/

/* Write your T-SQL query statement below */

select e.name as "Employee" from Employee e, Employee ee 
where ee.id=e.managerId and e.salary>ee.salary;

