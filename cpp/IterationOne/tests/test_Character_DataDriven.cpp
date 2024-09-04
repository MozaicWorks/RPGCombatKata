#include <vector>
#include "doctest.h"
#include "Character.h"
#include "CharacterAsserts.h"

using std::vector;

TEST_SUITE_BEGIN("unit");

TEST_CASE("New character is alive, at full health and at level 1"){
	Character character;

	CharacterAsserts(character).isNewAndValid();
}

TEST_CASE("Defender's health decreases after an attacker deals damage"){
	Character attacker;
	Character defender;
	int damage;
	int expectedHealth;

	SUBCASE("Damage 100"){
		damage = 100;
		expectedHealth = 900;
	}
	SUBCASE("Damage 200"){
		damage = 200;
		expectedHealth = 800;
	}
	SUBCASE("Damage 700"){
		damage = 700;
		expectedHealth = 300;
	}
	SUBCASE("Damage 1"){
		damage = 1;
		expectedHealth = 999;
	}
	SUBCASE("Damage 999"){
		damage = 999;
		expectedHealth = 1;
	}
	CAPTURE(damage);
	CAPTURE(expectedHealth);

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
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 200);

	healer.heal(defender, 100);

	CharacterAsserts(defender).hasHealth(900);
}

TEST_CASE("Healing a character has health capped at 1000"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 200);

	healer.heal(defender, 300);

	CharacterAsserts(defender).isAliveAtFullHealth();
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
