-- 코드를 입력하세요
select * from places
where host_id in (
    select host_id from (
        SELECT host_id, count(*) as cnt from places
        group by host_id having cnt>=2
    ) as a
)
order by id