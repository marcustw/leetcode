# Write your MySQL query statement below
SELECT Person.firstName, Person.lastName, Address.city, Address.state
FROM Address 
RIGHT JOIN Person
on Person.personId = Address.personId; 