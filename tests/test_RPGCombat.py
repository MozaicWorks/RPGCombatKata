from RPGCombat.RPGCombat import Character

class TestRPGCombat:
    def test_new_character_has_1000_health(self):
        arthur = Character()

        assert arthur.health == 1000
