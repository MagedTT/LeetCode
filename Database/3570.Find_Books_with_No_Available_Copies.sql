-- Problem Link: https://leetcode.com/problems/find-books-with-no-available-copies/

WITH CTE_Borrowed_Books AS
(
    SELECT
        book_id,
        COUNT(1) AS current_borrowers
    FROM borrowing_records
    WHERE return_date IS NULL
    GROUP BY book_id
)
SELECT
    lb.book_id,
    title,
    author,
    genre,
    publication_year,
    current_borrowers
FROM library_books AS lb
INNER JOIN CTE_Borrowed_Books AS ctebb
    ON lb.book_id = ctebb.book_id
WHERE total_copies = current_borrowers
ORDER BY current_borrowers DESC, title;