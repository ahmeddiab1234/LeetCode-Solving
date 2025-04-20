-- https://leetcode.com/problems/find-product-recommendation-pairs/description/


/* Write your T-SQL query statement below */

/* Write your T-SQL query statement below */

select 
    pp1.product_id as product1_id, 
    pp2.product_id as product2_id,
    p1.category as product1_category, 
    p2.category as product2_category, 
    count(distinct pp1.user_id) as customer_count

from productpurchases pp1
join productpurchases pp2 
    on pp1.user_id = pp2.user_id 
    and pp1.product_id < pp2.product_id

join productinfo p1
    on pp1.product_id = p1.product_id

join productinfo p2
    on pp2.product_id = p2.product_id

group by 
    pp1.product_id, 
    pp2.product_id,
    p1.category, 
    p2.category

having count(distinct pp1.user_id) >= 3

order by 
    customer_count desc, 
    product1_id, 
    product2_id;

