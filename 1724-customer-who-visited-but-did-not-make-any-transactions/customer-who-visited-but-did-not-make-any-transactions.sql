# Write your MySQL query statement below

select a.customer_id, count(a.customer_id) as count_no_trans
from visits as a
left join transactions as b 
on a.visit_id = b.visit_id
where b.transaction_id IS NULL
group by customer_id
;