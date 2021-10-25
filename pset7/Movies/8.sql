-- Write a SQL query to list the names of all people who starred in Toy Story

SELECT name -- Use SELECT to select from which colum you want your output, in this case we want name from the table people
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id -- Use FROM people to select which table you want to use, however the people table does not contain information about which movies the different actors stared in. I then solve this by using JOIN to join the people table with the stars table. Then I use ON stars.person_id = people.id where I ask that the colum person_id in the table stars should be equal to the colum people.id in the table people. Now we have access to person_id and movie_id, however we still need to access the title of the movie. The title of the movie is stored in the table movies. We then have to use JOIN again in almost the same way as before. Now that the tables are joined I can access the title field, which I need in the next step.
-- Byt om people og movies, gør forespørgslen hurtigere (siger Magnus), mangler at blive testet
WHERE title = "Toy Story"; -- Use WHERE title = "Toy Story" because we only want the names of people who stared in a movie with the title Toy Story, use ; to end the SQL statement

-- Result  4 rows
-- Runtime 2500-2550ms