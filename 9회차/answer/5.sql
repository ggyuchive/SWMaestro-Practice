-- 코드를 입력하세요
select a.cart_id from (
    SELECT cart_id from cart_products
    where name="Milk"
) as a
join (
    SELECT cart_id from cart_products
    where name="Yogurt"
) as b
on a.cart_id = b.cart_id
order by a.cart_id