-- 코드를 입력하세요
SELECT substr(product_code,1,2) as category, count(product_id) as products
from product
group by category
order by category