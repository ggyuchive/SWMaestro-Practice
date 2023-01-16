-- 코드를 입력하세요
select month(start_date) as MONTH, history.car_id as CAR_ID, count(history.car_id) as RECORDS
from car_rental_company_rental_history as history 
join
(
    SELECT car_id
    from car_rental_company_rental_history
    where month(start_date) between 8 and 10
    group by car_id having count(car_id)>=5
) as result
on history.car_id=result.car_id
where month(start_date) between 8 and 10
group by month, history.car_id
order by month, history.car_id desc