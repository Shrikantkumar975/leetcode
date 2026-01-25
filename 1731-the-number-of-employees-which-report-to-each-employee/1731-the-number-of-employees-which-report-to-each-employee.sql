# Write your MySQL query statement below
select e2.employee_id,e2.name,count(e1.employee_id) as reports_count,round(avg(e1.age*1.0),0) as average_age
from employees e2
join employees e1
on e2.employee_id = e1.reports_to
GROUP BY e2.employee_id, e2.name
order by employee_id