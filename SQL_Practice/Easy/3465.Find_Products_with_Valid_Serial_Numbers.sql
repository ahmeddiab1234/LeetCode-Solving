-- https://leetcode.com/problems/find-products-with-valid-serial-numbers/description/


/* Write your T-SQL query statement below */
select product_id, product_name, description from products
where  description like '%SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]%'
    and description not like '%SN[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9]%'
order by product_id;
