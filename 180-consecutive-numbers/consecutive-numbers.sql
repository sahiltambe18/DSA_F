# Write your MySQL query statement below

select distinct l.num as ConsecutiveNums from Logs l , Logs m , Logs n
where l.id = m.id-1 and l.id = n.id-2 and
l.num = m.num and l.num = n.num