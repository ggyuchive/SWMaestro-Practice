-- 코드를 입력하세요
SELECT FLAVOR from first_half
where total_order > 3000 and 
'fruit_based' = (select ingredient_type from icecream_info where first_half.flavor = icecream_info.flavor)
order by total_order desc