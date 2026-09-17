# Write your MySQL query statement below
#use a window function- dense rank

SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) AS "rank" FROM Scores;