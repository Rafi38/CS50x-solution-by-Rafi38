SELECT title
FROM movies
    JOIN ratings on ratings.movie_id = movies.id
WHERE movies.id in (
        SELECT movie_id
        FROM stars
        WHERE person_id = (
                SELECT id
                FROM people
                WHERE name = "Chadwick Boseman"
            )
    )
ORDER by ratings.rating DESC
LIMIT 5;