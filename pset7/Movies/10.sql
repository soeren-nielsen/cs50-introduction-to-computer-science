-- Write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0

SELECT DISTINCT name
-- I start by using SELECT to select from which column you want your output, in this case we want name from the table people. I also use DISTINCT to ensure that only unique values are returned, which ensures that each director only is shown once in the results eventhough they might have directed multiple movies with a ration of 9.00 or above
FROM people JOIN directors ON directors.person_id = people.id JOIN ratings ON ratings.movie_id = directors.movie_id
-- Use FROM people to select which table you want to use, however the people table does not contain information about which movies which directors directed. I solve this by using JOIN to join the people table with the directors table. Then I use ON directors.person_id = people.id where I ask that the column person_id in the table directors should be equal to the column people.id in the table people. Now I have access to person_id and movie_id, however we still need to know the rating of the movies. The rating of the movies are stored in the table ratings where I again use ON to set ratings.movie_id equal to directors.movie_id. Now that the 3 tables are joined and have access to the data needed for the query I can continue with the next step.
WHERE rating >= 9.0;
-- In the last step I use WHERE rating >= 9.00 because we only want those directors which have made a movie with a rating of equal to or greater than 9.00. I then use ; to end the SQL statement

-- Result 1841 rows
-- Runtime 2175-2275ms