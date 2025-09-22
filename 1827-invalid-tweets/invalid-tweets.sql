# Write your MySQL query statement below
Select tweet_id from Tweets group by content having Length(content) > 15;