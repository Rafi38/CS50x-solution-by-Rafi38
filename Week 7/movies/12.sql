SELECT title
FROM movies
WHERE id in (
        SELECT movie_id
        FROM stars
        WHERE person_id in (
                SELECT id
                FROM people
                WHERE name = "Helena Bonham Carter"
            )
    )
INTERSECT
SELECT title
FROM movies
WHERE id in (
        SELECT movie_id
        FROM stars
        WHERE person_id in (
                SELECT id
                FROM people
                WHERE name = "Johnny Depp"
            )
    );