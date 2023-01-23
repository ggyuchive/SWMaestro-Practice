-- 코드를 입력하세요
SELECT product_code, sum_sales*price as sales from
(
    select product_id, sum(sales_amount) as sum_sales
    from offline_sale
    group by product_id
) as offline_sale
join product on offline_sale.product_id=product.product_id
order by sales desc, product_code