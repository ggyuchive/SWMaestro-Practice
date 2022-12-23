-- 코드를 입력하세요
SELECT DR_NAME, DR_ID, MCDP_CD, SUBSTRING(HIRE_YMD,1,11) as HIRE_YMD
from DOCTOR
where MCDP_CD in ('CS','GS')
order by HIRE_YMD desc, HIRE_YMD