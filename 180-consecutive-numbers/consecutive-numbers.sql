# Write your MySQL query statement below
select
    distinct l.num as ConsecutiveNums
from
    Logs as l inner join Logs as m
    on l.id = m.id + 1
    inner join Logs as n
    on l.id = n.id - 1
where
    l.num = m.num and l.num = n.num;