#include "CharacterBuilder.h"

CharacterBuilder CharacterBuilder::aCharacter(){
	CharacterBuilder characterBuilder;
	return characterBuilder;
}

CharacterBuilder CharacterBuilder::aliveWithHealth(int health){
	this->health = health;
	this->alive = true;
	return *this;
}

CharacterBuilder CharacterBuilder::dead(){
	this->health = 0;
	this->alive = false;
	return *this;
}

CharacterBuilder CharacterBuilder::almostDeadCharacter(){
	return CharacterBuilder::aCharacter().aliveWithHealth(1);
}


Character CharacterBuilder::build() const {
	Character character;
	if(health == 1000){
		return character;
	}
	if(!alive){
		Character other;
		other.dealDamage(character, 1001);
		return character;
	}

	Character other;
	other.dealDamage(character, character.health() - health);
	return character;
}
