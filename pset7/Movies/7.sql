-- Write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title

SELECT title, rating -- Use SELECT to select from which colums you want your output, in this case we want title from the table movies and rating from the table ratings
FROM movies JOIN ratings ON movies.id = ratings.movie_id -- Use FROM movies to select which table you want to use, however the movies table does not contain data about the rating for each movie. I then solve this by using JOIN to join the movies table table with the ratings table. Then I use ON movies.id = ratings.movie_id where I ask that the colum ID in the table movies should be equal to the colum movie_id in the table ratings. This enables me to access data in the table movies, which then makes it possible for me to get the data about which ratings the different movies have.
WHERE year = 2010 -- Use WHERE year = 2010 because we only want the movies released in 2010
ORDER BY rating DESC, title ASC; -- Use ORDER BY rating DESC because we want the movies in descending order by rating (descending = from highest numerical value to lowest). However if two movies or more have the same rating we want to order their titles in alphabetical order, which is done by using ASC (ascending = first in the alphabet to last in the alphabet)

-- Result  6835 rows
-- Runtime 270-310ms