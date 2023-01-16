-- 코드를 입력하세요
select history_id, 
round(if(date<7, daily_fee*date, daily_fee*date*(100-discount_rate)/100),0) as fee
from 
(
    SELECT history_id, history.car_id, daily_fee, datediff(end_date,start_date)+1 as date,
    if(datediff(end_date,start_date)>=90,'90일 이상',
    if(datediff(end_date,start_date)>=30,'30일 이상','7일 이상')) as duration_type
    from car_rental_company_rental_history as history
    join car_rental_company_car as car
    on history.car_id=car.car_id
    where car_type="트럭"
) as history
join
(
    select duration_type, discount_rate 
    from car_rental_company_discount_plan
    where car_type="트럭"
) as discount
on history.duration_type=discount.duration_type
order by fee desc, history_id desc