SELECT customer_id
FROM Customer
GROUP BY customer_id
having count(distinct product_key)= (select count(*) from product)