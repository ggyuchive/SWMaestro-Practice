-- 코드를 입력하세요
SELECT MCDP_CD as '진료과코드', COUNT(PT_NO) as '5월예약건수'
from appointment
where apnt_ymd like '2022-05%'
group by MCDP_CD
order by COUNT(PT_NO), MCDP_CD