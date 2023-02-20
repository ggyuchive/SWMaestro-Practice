-- 코드를 입력하세요
select maxi.category, max_price, product_name from food_product
join
(
    SELECT category, max(price) as max_price
    from food_product
    group by category having category in ('과자', '국', '김치', '식용유')
) as maxi
on maxi.category = food_product.category
where maxi.max_price = food_product.price
order by max_price desc