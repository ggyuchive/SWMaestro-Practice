-- 코드를 입력하세요
SELECT year(sales_date) as year, month(sales_date) as month, gender, count(distinct user_info.user_id) as users
from online_sale join user_info
on online_sale.user_id=user_info.user_id
group by year, month, gender having not isnull(gender)
order by year, month, gender