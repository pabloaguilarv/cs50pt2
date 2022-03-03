SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id and
stars.person_id = people.id
WHERE people.name = "Johnny Depp"
INTERSECT
SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id and
stars.person_id = people.id
WHERE people.name = "Helena Bonham Carter";