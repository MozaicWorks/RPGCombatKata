default: test run

init:
	pipenv install

test: 
	pipenv run python -m unittest 

run:
	pipenv run python RPGCombat/RPGCombat.py

.SILENT:
