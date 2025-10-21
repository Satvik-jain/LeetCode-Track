select data.name from
(
    select e2.id, e2.name
    from employee e1
    left join employee e2
    on e1.managerid = e2.id
) as data
group by id 
having count(id) > 4;