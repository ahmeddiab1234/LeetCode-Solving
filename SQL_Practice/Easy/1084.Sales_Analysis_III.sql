-- https://leetcode.com/problems/sales-analysis-iii/description/


/* Write your T-SQL query statement below */
select s.product_id, product_name 
from Product p  join(
    select product_id from Sales
    group by product_id 
    having
    max(case when sale_date between '2019-01-01' and '2019-03-31' then 1 else 0 end)=1
    and max(case when sale_date>'2019-03-31' or sale_date<'2019-01-01' then 1 else 0 end)=0
) s
on p.product_id=s.product_id;


