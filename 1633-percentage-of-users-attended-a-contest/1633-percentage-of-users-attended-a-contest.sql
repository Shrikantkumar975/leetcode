# Write your MySQL query statement below
select r.contest_id,
    Round(COUNT(DISTINCT r.user_id) * 100.0/ (select Count(*) from users),2) as percentage
from register r
group by r.contest_id
order by percentage desc