# Write your MySQL query statement below
delete p from Person p 
join Person d where p.id>d.id and p.email=d.email
