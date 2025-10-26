with total as (
    select count(user_id) as cnt
    from users
)

select contest_id, round(100*count(distinct user_id)/t.cnt, 2) as percentage
from register
cross join total t
group by contest_id
order by percentage desc, contest_id asc