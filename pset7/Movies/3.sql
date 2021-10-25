-- Write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order

SELECT title -- Use SELECT to select from which colum you want your output, in this case we want title from the table movies
FROM movies -- Use FROM movies to select which table you want to use, in this case movies
WHERE year >= 2018 -- Use WHERE year >= 2018 because we only want the movies released in 2018 or after (equal to or higher than 2018)
ORDER BY title ASC; -- Use ORDER BY title ASC because we want the titles ordered in alphabetical order (ascending)

-- Result 35755 rows
-- Runtime 340-360ms