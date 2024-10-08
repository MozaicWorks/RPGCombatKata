from RPGCombat.Character import Character

class TestRPGCombat:

    def test_new_character_is_alive_has_full_health_and_level_1(self):
        arthur = Character()

        self.assertFullHealth(arthur)
        assert arthur.level == 1

    def test_character_is_damaged(self):
        arthur = Character()

        arthur.takeDamage(100)

        self.assertAlive(arthur, 900)

    def test_character_dies_from_damage(self):
        arthur = Character()

        arthur.takeDamage(Character.MAX_HEALTH)

        self.assertDead(arthur)

    def test_character_is_healed(self):
        arthur = Character()
        arthur.takeDamage(50)

        arthur.heal(40)

        self.assertAlive(arthur, 990)

    def test_character_is_healed_to_full(self):
        arthur = Character()
        arthur.takeDamage(50)

        arthur.heal(51)

        self.assertFullHealth(arthur)

    def test_cannot_heal_dead_character(self):
        arthur = Character()
        arthur.takeDamage(Character.MAX_HEALTH)

        arthur.heal(Character.MAX_HEALTH)

        self.assertDead(arthur)

    def test_deal_damage_to_another_character(self):
        arthur = Character()
        merlin = Character()

        arthur.dealDamageTo(merlin, 10)

        self.assertAlive(merlin, 990)

    def test_cannot_deal_self_damage(self):
        arthur = Character()

        arthur.dealDamageTo(arthur, 10)

        self.assertFullHealth(arthur)

    def test_deal_damage_to_lower_level(self):
        arthur = Character()
        arthur.level = 6
        novice = Character()

        arthur.dealDamageTo(novice, 10)

        self.assertFullHealth(arthur)
        self.assertAlive(novice, 985)

    def test_deal_damage_to_higher_level(self):
        arthur = Character()
        arthur.level = 6
        novice = Character()

        novice.dealDamageTo(arthur, 10)

        self.assertFullHealth(novice)
        self.assertAlive(arthur, 995)


    def assertDead(self, character):
        assert character.health == 0
        assert not character.isAlive()

    def assertAlive(self, character, expectedHealth):
        assert character.health == expectedHealth
        assert character.isAlive()

    def assertFullHealth(self, character):
        return self.assertAlive(character, Character.MAX_HEALTH)
