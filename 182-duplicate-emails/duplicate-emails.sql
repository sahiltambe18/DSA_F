# Write your MySQL query statement below

select distinct p.email as Email from Person p , Person q
where p.id!=q.id and p.email=q.email