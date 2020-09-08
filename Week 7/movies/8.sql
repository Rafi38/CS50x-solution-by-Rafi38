SELECT name
FROM people
WHERE id in (
		SELECT person_id
		FROM stars
		WHERE movie_id in (
				SELECT id
				from movies
				WHERE title = "Toy Story"
			)
	);