#include "Character.h"
#pragma once

class CharacterBuilder{

	
	private:
		int health;
		bool alive;

		CharacterBuilder(): health(1000), alive(true){

		}

	public:
		static CharacterBuilder aCharacter();

		static CharacterBuilder almostDeadCharacter();

		CharacterBuilder aliveWithHealth(int health);

		CharacterBuilder dead();

		Character build() const; 
};
