SELECT people.name
FROM people, stars, movies
ON people.id = stars.person_id and movies.id = stars.movie_id
WHERE movies.id IN
(SELECT stars.movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE people.name = "Kevin Bacon" and people.birth = 1958) and NOT people.name = "Kevin Bacon";