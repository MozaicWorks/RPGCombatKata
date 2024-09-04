#include "doctest.h"
#include "Character.h"

TEST_SUITE_BEGIN("unit");

TEST_CASE("New character health is 1000"){
	Character character;

	CHECK_EQ(1000, character.health());
}

TEST_CASE("New character is alive"){
	Character character;

	CHECK(character.isAlive());
}

TEST_CASE("New character has level 1"){
	Character character;

	CHECK_EQ(1, character.level());
}

TEST_CASE("Deal damage"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 100);

	CHECK_EQ(900, defender.health());
}

TEST_CASE("Health becomes 0 when damage higher than health"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 1100);

	CHECK_EQ(0, defender.health());
}

TEST_CASE("Defender dies when damage higher than health"){
	Character attacker;
	Character defender;

	attacker.dealDamage(defender, 1100);

	CHECK_FALSE(defender.isAlive());
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

	CHECK_EQ(1000, defender.health());

}

TEST_CASE("Healing has no effect on dead character's health"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 1100);

	healer.heal(defender, 300);

	CHECK_EQ(0, defender.health());
}

TEST_CASE("Healing does not revive a dead character"){
	Character attacker;
	Character defender;
	Character healer;
	attacker.dealDamage(defender, 1100);

	healer.heal(defender, 300);

	CHECK_FALSE(defender.isAlive());
}


TEST_SUITE_END();

