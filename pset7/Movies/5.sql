-- Write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order

SELECT title, year -- Use SELECT to select from which colums you want your output, in this case we want title and the year from the table movies
FROM movies -- Use FROM movies to select which table you want to use, in this case movies because that is where title and year are stored
WHERE title LIKE "Harry Potter%" -- Use WHERE title LIKE "Harry Potter%" because we only want to print the titles where Harry Potter is included. The wildcard % means that the title needs to start with Harry Potter, but whatever comes after doesn't matter.
ORDER BY year ASC; -- Use ORDER BY year ASC because we want the titles ordered in chronological order (ascending = earliest to latest based on the year the movie was released)

-- Result 10 rows
-- Runtime 135-165ms