# Write your MySQL query statement below

SELECT E.name, EU.unique_id
FROM Employees E
LEFT JOIN EmployeeUNI EU
ON E.id = EU.id;
