# Write your MySQL query statement below
-- subdate(recorddate, 1)

select a.id
from weather a
left join weather b
on a.recordDate = adddate(b.recordDate, 1)
where a.temperature > b.temperature