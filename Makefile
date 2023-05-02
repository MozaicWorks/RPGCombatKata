default: test run

init:
	pipenv install

tests: .FORCE
	pipenv run pytest --no-header --tb=no --quiet -v tests/

run:
	pipenv run python RPGCombat/RPGCombat.py

.FORCE:

.SILENT:
