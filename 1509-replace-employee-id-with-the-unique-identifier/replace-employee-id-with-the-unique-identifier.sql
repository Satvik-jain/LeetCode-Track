# Write your MySQL query statement below
select unique_id, name
from employees as a

left join employeeuni as b
on a.id = b.id;