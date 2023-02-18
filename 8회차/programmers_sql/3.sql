-- 코드를 입력하세요
SELECT car_id from car_rental_company_car
where car_type="세단" and car_id in (
    select distinct(car_id) from car_rental_company_rental_history
    where month(start_date) = 10
)
order by car_id desc