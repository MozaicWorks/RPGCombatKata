#include <vector>
#include "doctest.h"
#include "Character.h"
#include "CharacterAsserts.h"
#include "CharacterBuilder.h"

using std::vector;

TEST_SUITE_BEGIN("unit");

TEST_CASE("New character is alive, at full health and at level 1"){
	CharacterAsserts(CharacterBuilder::aCharacter().build()).isNewAndValid();
}

TEST_CASE("Defender's health decreases after an attacker deals damage"){
	int defenderInitialHealth;
	int damage;
	int expectedHealth;

	SUBCASE("Damage 1 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 1;
		expectedHealth = 999;
	}
	SUBCASE("Damage 200 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 200;
		expectedHealth = 800;
	}
	SUBCASE("Damage 999 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 999;
		expectedHealth = 1;
	}
	SUBCASE("Damage 998 To Health 999"){
		defenderInitialHealth = 999;
		damage = 998;
		expectedHealth = 1;
	}
	SUBCASE("Damage 1 To Health 2"){
		defenderInitialHealth = 2;
		damage = 1;
		expectedHealth = 1;
	}

	CAPTURE(defenderInitialHealth);
	CAPTURE(damage);
	CAPTURE(expectedHealth);

	Character attacker;
	Character defender = CharacterBuilder::aCharacter().aliveWithHealth(defenderInitialHealth).build();

	attacker.dealDamage(defender, damage);

	CharacterAsserts(defender).isAlive();
	CharacterAsserts(defender).hasHealth(expectedHealth);
}

TEST_CASE("Defender dies and health goes to 0 when damage higher than health"){
	Character attacker;
	Character defender;
	vector<int> damages;

	SUBCASE("Damage 1001"){
		damages = {1001};
	}
	SUBCASE("Subsequent attacks total damage 1001"){
		damages = {10, 133, 234, 77, 14, 320, 213 };
	}

	SUBCASE("Damage 1100"){
		damages = {1100};
	}
	CAPTURE(damages);

	for(int theDamage : damages){
		attacker.dealDamage(defender, theDamage);
	}

	CharacterAsserts(defender).isDead();
}

TEST_CASE("Healing a character increases their health"){
	Character character = CharacterBuilder::aCharacter().aliveWithHealth(800).build();
	Character healer;

	healer.heal(character, 100);

	CharacterAsserts(character).hasHealth(900);
}

TEST_CASE("Healing a character has health capped at 1000"){
	Character character = CharacterBuilder::aCharacter().aliveWithHealth(800).build();
	Character healer;

	healer.heal(character, 300);

	CharacterAsserts(character).isAliveAtFullHealth();
}

TEST_CASE("Healing does not revive or increase health of a dead character"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 1100);

	healer.heal(defender, 300);

	CharacterAsserts(defender).isDead();
}


TEST_SUITE_END();
