# Write your MySQL query statement below
select c.customer_id
from customer c
join product p
on p.product_key = c.product_key
group by customer_id
having count(distinct c.product_key) = (select count(*) from product)