-- 코드를 입력하세요
select car_id, a.car_type, round(daily_fee*30*(100-discount_rate)/100) as fee
from car_rental_company_car
join (
    select * from car_rental_company_discount_plan
    where duration_type="30일 이상"
    ) as a on a.car_type = car_rental_company_car.car_type
where (a.car_type = "세단" or a.car_type = "SUV") and car_id not in (
    SELECT car_id from car_rental_company_rental_history
    where not (end_date <= "2022-11-01" or start_date > "2022-11-30")
)
and daily_fee*30*(100-discount_rate)/100>=500000 and daily_fee*30*(100-discount_rate)/100<2000000
order by fee desc, a.car_type, car_id desc