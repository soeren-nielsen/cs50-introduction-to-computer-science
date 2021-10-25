-- Write a SQL query to determine the birth year of Emma Stone

SELECT birth -- Use SELECT to select from which colum you want your output, in this case we want birth from the table people
FROM people -- Use FROM people to select which table you want to use, in this case people
WHERE name = "Emma Stone"; -- Use WHERE name = "Emma Stone" because we only want the birth(year) of Emma Stone, use ; to end the SQL statement

-- Result 1 row
-- Runtime 165-175ms