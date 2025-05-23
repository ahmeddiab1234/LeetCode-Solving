-- https://leetcode.com/problems/market-analysis-i/description/

/* Write your T-SQL query statement below */
select u.user_id as buyer_id, u.join_date, count(o.order_id) as orders_in_2019
from Users u left join orders o on user_id=buyer_id
and year(o.order_date) = 2019
group by u.user_id, u.join_date;
