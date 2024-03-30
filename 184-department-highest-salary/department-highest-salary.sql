# Write your MySQL query statement below

with cte as(
select e.name as Employee, e.salary, d.name as Department 
from Employee e join Department d
on e.departmentId = d.id 
)
select Employee, salary,Department from cte having (Department,salary) in 
(select Department,max(salary) as salary from cte group by Department)