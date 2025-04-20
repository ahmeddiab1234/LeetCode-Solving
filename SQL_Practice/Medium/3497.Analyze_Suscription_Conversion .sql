-- https://leetcode.com/problems/analyze-subscription-conversion/description/


/* Write your T-SQL query statement below */
select user_id, 
    round(avg(case when activity_type = 'free_trial' then cast(activity_duration as decimal(10,2)) end), 2) as trial_avg_duration,
    
    round(avg(case when activity_type = 'paid' then cast(activity_duration as decimal(10,2)) end), 2) as paid_avg_duration 
from UserActivity
group by user_id
having avg(case when activity_type = 'paid' then 1 else null end) > 0
order by user_id;
