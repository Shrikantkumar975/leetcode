# Write your MySQL query statement below
SELECT product_name, year, price 
FROM sales s
join product p 
on p.product_id = s.product_id