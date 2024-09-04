default: test run

init:
	pipenv install

tests: .FORCE
	pipenv run pytest --no-header --tb=no  -v tests/

run:
	pipenv run python src/RPGCombat/RPGCombat.py

.FORCE:

.SILENT:
