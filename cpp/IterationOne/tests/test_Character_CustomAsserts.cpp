#include "doctest.h"
#include "Character.h"

TEST_SUITE_BEGIN("unit");

void assertHasFullHealth(const Character& character){
	CHECK_EQ(1000, character.health());
}

void assertIsAlive(const Character& character){
	CHECK(character.isAlive());
}

void assertIsAliveAtFullHealth(const Character& character){
	assertIsAlive(character);
	assertHasFullHealth(character);
}

void assertIsNotAlive(const Character& character){
	CHECK_FALSE(character.isAlive());
}

void assertHasNoHealth(const Character& character){
	CHECK_EQ(0, character.health());
}

void assertIsDead(const Character& character){
	assertIsNotAlive(character);
	assertHasNoHealth(character);
}

void assertHasHealth(const Character& character, const int expectedHealth){
	CHECK_EQ(expectedHealth, character.health());
}

void assertAtLevel(const Character& character, const int expectedLevel){
	CHECK_EQ(expectedLevel, character.level());
}

void assertNewCharacterIsValid(const Character& character){
	assertIsAliveAtFullHealth(character);
	assertAtLevel(character, 1);
}

TEST_CASE("New character is alive, at full health and at level 1"){
	Character character;

	assertNewCharacterIsValid(character);
}

TEST_CASE("Defender's health decreases after an attacker deals damage"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 100);

	assertHasHealth(defender, 900);
}

TEST_CASE("Defender dies and health goes to 0 when damage higher than health"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 1100);

	assertIsDead(defender);
}

TEST_CASE("Healing a character increases their health"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 200);

	healer.heal(defender, 100);

	CHECK_EQ(900, defender.health());
}

TEST_CASE("Healing a character has health capped at 1000"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 200);

	healer.heal(defender, 300);

	assertIsAliveAtFullHealth(defender);
}

TEST_CASE("Healing does not revive or increase health of a dead character"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 1100);

	healer.heal(defender, 300);

	assertIsDead(defender);
}


TEST_SUITE_END();

