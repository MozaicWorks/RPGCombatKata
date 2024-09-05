#include <vector>
#include "doctest.h"
#include "Character.h"
#include "CharacterAsserts.h"
#include "CharacterBuilder.h"

using std::vector;

TEST_SUITE_BEGIN("unit");

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
	Character character = CharacterBuilder::aCharacter().dead().build();
	Character healer;

	healer.heal(character, 300);

	CharacterAsserts(character).isDead();
}

TEST_SUITE_END();
