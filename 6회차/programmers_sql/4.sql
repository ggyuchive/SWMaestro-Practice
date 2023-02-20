-- 코드를 입력하세요
SELECT animal_ins.animal_id, animal_ins.name from animal_ins
join animal_outs on animal_ins.animal_id = animal_outs.animal_id
where animal_ins.datetime > animal_outs.datetime
order by animal_ins.datetime