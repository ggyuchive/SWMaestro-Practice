-- 코드를 입력하세요
select maxi.food_type, rest_id, rest_name, maxi.favorites from rest_info
join
(
    SELECT food_type, max(favorites) as favorites
    from rest_info group by food_type
) as maxi
on maxi.food_type = rest_info.food_type
where maxi.favorites = rest_info.favorites
order by food_type desc