-- 코드를 입력하세요
SELECT animal_ins.animal_id, animal_ins.animal_type, animal_ins.name from animal_ins
join animal_outs
on animal_ins.animal_id = animal_outs.animal_id
where sex_upon_intake like "Intact%" and (sex_upon_outcome like "Spayed%" or sex_upon_outcome like "Neutered%")
order by animal_ins.animal_id