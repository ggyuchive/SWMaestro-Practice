-- 코드를 입력하세요
select author_id, author_name, category, SUM(total_sales) as total_sales
from (SELECT book.author_id, author_name, category, SUM(sales)*price as total_sales
from book_sales join book on book_sales.book_id = book.book_id
                join author on book.author_id = author.author_id
where date_format(sales_date,"%Y-%m")="2022-01"
group by book.book_id, category) as result
group by author_id, category
order by author_id, category desc