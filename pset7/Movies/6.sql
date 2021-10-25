-- Write a SQL query to determine the average rating of all movies released in 2012

SELECT AVG(rating) -- Use SELECT to select from which colums you want your output, in this case we want the rating, however we want the average rating so we use the function AVG (average)
FROM ratings JOIN movies ON movies.id = ratings.movie_id -- Use FROM ratings to select which table you want to use, however the ratings table does not contain data about the year a movie was released. I then solve this by using JOIN to join the ratings table with the movies table which contains data about the year a movie was released. Then I use ON movies.id = ratings.movie_id where I ask that colum ID in the table movies should be equal to the colum movie_id in the table ratings. This enables me to access data in the table movies, which then makes it possible for me to get the data about which year the movie was released.
WHERE year = 2012; -- Use WHERE year = 2012 because we only want the movies released in 2012, use ; to end the SQL statement

-- Result  1 row
-- Runtime 200-240ms