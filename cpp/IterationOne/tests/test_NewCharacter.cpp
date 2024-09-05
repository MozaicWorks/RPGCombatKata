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

TEST_SUITE_END();
