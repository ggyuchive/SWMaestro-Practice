-- 코드를 입력하세요
select p.product_id, product_name, total*price as total_sales from food_product
join (
    SELECT product_id, sum(amount) as total
    from food_order
    where year(produce_date)=2022 and month(produce_date)=5
    group by product_id
) as p
on food_product.product_id = p.product_id
order by total_sales desc, product_id