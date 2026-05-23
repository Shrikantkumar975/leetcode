# Write your MySQL query statement belows
-- select customer_number from (select customer_number,count(customer_number) as c from orders o
-- group by customer_number) as t

select customer_number from orders
group by customer_number 
order by count(*) desc
limit 1