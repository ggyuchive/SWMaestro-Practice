-- 코드를 입력하세요
select flavor 
from (
    select first_half.flavor, first_half.total_order+july.total_order as realtotal
    from
        (select flavor, SUM(total_order) as total_order from first_half
        group by flavor) as first_half 
        join
        (select flavor, SUM(total_order) as total_order from july
        group by flavor) as july
        on first_half.flavor=july.flavor
        order by realtotal desc limit 3
) as result