



/*
This query retrieves each product’s name, sales year, and price.
It works with both JOIN and LEFT JOIN because:
- Every product_id in the sales table exists in the product table.
- The relationship is enforced through a foreign key.
Hence, both joins produce the same output.
*/

SELECT p.product_name, s.year, s.price
FROM sales AS s
LEFT JOIN product AS p
ON p.product_id = s.product_id;
