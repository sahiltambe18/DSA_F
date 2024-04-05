# Write your MySQL query statement below

select s.id from Weather s ,weather t 
where DATEDIFF( s.recordDate , t.recordDate)=1 and s.temperature > t.temperature