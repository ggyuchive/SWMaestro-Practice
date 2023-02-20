-- 코드를 입력하세요
select member_name, review_text, date_format(review_date,"%Y-%m-%d") from rest_review
join member_profile on rest_review.member_id = member_profile.member_id
where rest_review.member_id in
(
    select member_id from
    (
        SELECT member_profile.member_id, count(*) as counting from rest_review
        join member_profile on rest_review.member_id = member_profile.member_id
        group by rest_review.member_id
        order by counting desc limit 1
    ) as a
)
order by review_date, review_text