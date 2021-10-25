-- Write a SQL query to list the titles of all movies released in 2008

SELECT title -- Use SELECT to select from which colum you want your output, in this case we want title from the table movies
FROM movies -- Use FROM movies to select which table you want to use, in this case movies
WHERE year = 2008; -- Use WHERE year = 2008 because we only want the movies released in 2008, use ; to end the SQL statement

-- Result 9480 rows
-- Runtime 55-65ms