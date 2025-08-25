# Write your MySQL query statement below
select 
(select distinct salary # as col not table
from employee
order by salary desc
limit 1
offset 1)
as secondHighestSalary;