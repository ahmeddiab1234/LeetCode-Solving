-- https://leetcode.com/problems/find-students-who-improved/description/


/* Write your T-SQL query statement below */

with cte as (
    select student_id, subject, score, exam_date,
            row_number() over (partition by student_id, subject order by exam_date asc) as rn_first,
            row_number() over (partition by student_id, subject order by exam_date desc) as rn_last
    from scores
)
select a.student_id, a.subject, a.score as first_score, b.score as latest_score
from cte a join cte b
    on a.student_id = b.student_id and a.subject = b.subject
where a.rn_first = 1 and b.rn_last = 1 and a.score < b.score
order by a.student_id, a.subject;
