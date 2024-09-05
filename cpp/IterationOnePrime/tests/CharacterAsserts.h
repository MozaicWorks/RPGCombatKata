#include "doctest.h"
#include "Character.h"
#pragma once

class CharacterAsserts{
	private:
		const Character& character;

	public:
		CharacterAsserts(const Character& character): character(character){}

		void hasFullHealth() const {
			CHECK_EQ(1000, character.health());
		}

		void isAlive() const {
			CHECK(character.isAlive());
		}

		void isAliveAtFullHealth() const {
			isAlive();
			hasFullHealth();
		}

		void isNotAlive() const {
			CHECK_FALSE(character.isAlive());
		}

		void hasNoHealth() const {
			CHECK_EQ(0, character.health());
		}

		void isDead() const {
			isNotAlive();
			hasNoHealth();
		}

		void hasHealth(const int expectedHealth){
			CHECK_EQ(expectedHealth, character.health());
		}

		void isAtLevel(const int expectedLevel){
			CHECK_EQ(expectedLevel, character.level());
		}

		void isNewAndValid(){
			isAliveAtFullHealth();
			isAtLevel(1);
		}
};
