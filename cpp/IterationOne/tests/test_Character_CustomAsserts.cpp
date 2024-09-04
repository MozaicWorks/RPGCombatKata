#include "doctest.h"
#include "Character.h"
#include "CharacterAsserts.h"

TEST_SUITE_BEGIN("unit");

TEST_CASE("New character is alive, at full health and at level 1"){
	Character character;

	CharacterAsserts(character).isNewAndValid();
}

TEST_CASE("Defender's health decreases after an attacker deals damage"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 100);

	CharacterAsserts(defender).hasHealth(900);
}

TEST_CASE("Defender dies and health goes to 0 when damage higher than health"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 1100);

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
