# Write your MySQL query statement below



select r.contest_id, round(100*count(contest_id)/r.cnt ,2) as percentage
from register r
join (select count(*) as cnt from users) r
group by r.contest_id
order by 
percentage desc,
contest_id asc
