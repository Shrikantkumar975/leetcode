# Write your MySQL query statement below
select e.name,IFNULL(b.bonus,NULL) as bonus
from employee e
left join bonus b
on e.empid = b.empid
where bonus < 1000 || bonus is NULL