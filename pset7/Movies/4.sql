-- Write a SQL query to determine the number of movies with an IMDb rating of 10.0

SELECT COUNT(movie_id) -- Use SELECT to select from which colum you want your output, in this case we don't need the titles we just need the number. Therefore we use COUNT to count the number of movie IDs with a rating of 10.0
FROM ratings -- Use FROM ratings to select which table you want to use, in this case ratings because that is were the rating for each movie is stored
WHERE rating = 10.0; -- Use WHERE rating = 10.00 because we only want those with a rating of 10.00, use ; to end the SQL statement

-- Result 1 row with the count of 12
-- Runtime 60-100ms