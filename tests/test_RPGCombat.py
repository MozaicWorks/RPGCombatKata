from RPGCombat.RPGCombat import Character

class TestRPGCombat:
    def test_new_character_is_alive_has_1000_health_and_level_1(self):
        arthur = Character()

        assert arthur.health == 1000
        assert arthur.level == 1
        assert arthur.alive
