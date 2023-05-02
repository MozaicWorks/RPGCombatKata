from RPGCombat.Character import Character

class TestRPGCombat:
    def test_new_character_is_alive_has_1000_health_and_level_1(self):
        arthur = Character()

        assert arthur.health == 1000
        assert arthur.level == 1
        assert arthur.alive

    def test_character_is_damaged(self):
        arthur = Character()
        arthur.takeDamage(10)

        assert arthur.health == 990

    def test_character_dies_from_damage(self):
        arthur = Character()

        arthur.takeDamage(1001)

        assert arthur.health == 0
        assert not arthur.alive
