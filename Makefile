default: test run

init:
	pipenv install

test: 
	pipenv run pytest --no-header --tb=no --quiet tests/

run:
	pipenv run python RPGCombat/RPGCombat.py

.SILENT:
