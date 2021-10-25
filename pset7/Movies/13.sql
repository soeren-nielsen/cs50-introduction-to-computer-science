-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT name -- I start by using SELECT to select from which colum I want my output, in this case I want name from the table people, however i also use DISTINCT because I want the names of people who starred in a movie with Kevin Bacon to appear once in my results, eventhough they might have starred in multiple movies with Kevin Bacon
FROM stars JOIN people ON stars.person_id = people.id -- Then I use FROM people to select the table people, however the people table does not contain information about which movies the different actors starred in. I then solve this by using JOIN to join the people table with the stars table. Then I use ON stars.person_id = [people.id](http://people.id/) where I ask that the column person_id in the table stars to be equal to the column [people.id](http://people.id/) in the table people. Now I have access to person_id and movie_id and I can continue to the next step.
WHERE movie_id IN -- Here I use WHERE movie_id IN, I use the IN operator because it allows me to specify multiple values in a WHERE clause
    (SELECT movie_id -- Here I start by making a nested query where I use SELECT movie_id because for this nested query I wan't the output to be from the column movie_id in the table stars
    FROM people JOIN stars on stars.person_id = people.id -- Here I do the same as earlier where i JOIN the people table and the stars table
    WHERE birth = 1958 and name = "Kevin Bacon") -- Then I use WHERE birth = 1958 and name = "Kevin Bacon" because I only want the Kevin Bacon born in 1958 and then end the nested query
    -- By the end of this nested query we should have a list of the people (including Kevin Bacon) who starred in a movie with Kevin Bacon
AND name != "Kevin Bacon"; -- Then I use AND name != (not equal to) Kevin Bacon, which should filter out Kevin Bacon from the nested query from before

-- Result 176 rows
-- Runtime 11000-13000ms