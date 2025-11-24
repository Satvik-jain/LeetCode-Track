# Write your MySQL query statement below
select v.customer_id, sum(t.cnt is null) as count_no_trans
from visits v
left join (
    select count(transaction_id) as cnt, visit_id
    from transactions
    group by visit_id
    ) t
on v.visit_id = t.visit_id
where t.cnt is null
group by v.customer_id

