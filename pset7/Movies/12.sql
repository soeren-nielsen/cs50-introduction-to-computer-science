-- Write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT title -- First I use SELECT to select from which column I want my output, in this case I want title from the table movies because I have to list all the titles
FROM people JOIN stars ON stars.person_id = people.id JOIN movies on movies.id = stars.movie_id -- Then I use FROM people to select which table I want to use, however the people table does not contain information about which movies the different actors stared in. I then solve this by using JOIN to join the people table with the stars table. Then I use ON stars.person_id = people.id where I ask that the colum person_id in the table stars should be equal to the colum people.id in the table people. Now we have access to person_id and movie_id, however we still need to access the title of the movies. The title of the movies are stored in the table movies. We then have to use JOIN again in almost the same way as before. Now that the tables are joined I can access the title. Then I need to filter the results so that it's only titles of movies that Johnny Depp starred in.
WHERE name = "Johnny Depp" -- I use WHERE name = "Johnny Depp" because for this part of the query I only want the titles of the movies he starred in.
INTERSECT -- Then I use INTERSECT which is used to combine two SELECT statements, however INTERSECT only returns rows from the first SELECT statement that are identical to a row in the second SELECT statement. This means that the result should be that only the titles of movies both Johnny Depp and Helena Bonham Carter starred in.
SELECT title -- The same as the first SELECT statement
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id -- The same as above
WHERE name = "Helena Bonham Carter" -- The same as above, instead that here we only want the titles of movies Helena Bonham Carter starred in

-- Result 6 rows
-- Runtime 12000-12800 ms