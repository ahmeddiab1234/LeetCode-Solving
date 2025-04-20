-- https://leetcode.com/problems/capital-gainloss/description/


/* Write your T-SQL query statement below */
select stock_name, 
sum(case when operation='Sell' then price else -1*price end) as capital_gain_loss
from Stocks group by stock_name;
