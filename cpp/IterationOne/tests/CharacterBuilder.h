#include "Character.h"

class CharacterBuilder{

	
	private:
		int health;
		bool alive;

		CharacterBuilder(): health(1000), alive(true){

		}

	public:
		static CharacterBuilder aCharacter();

		static CharacterBuilder almostDeadCharacter();

		CharacterBuilder aliveWithHealth(int health){
			this->health = health;
			this->alive = true;
			return *this;
		}

		CharacterBuilder dead(){
			this->health = 0;
			this->alive = false;
			return *this;
		}

		Character build() const {
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
};


CharacterBuilder CharacterBuilder::aCharacter(){
	CharacterBuilder characterBuilder;
	return characterBuilder;
}


CharacterBuilder CharacterBuilder::almostDeadCharacter(){
	return CharacterBuilder::aCharacter().aliveWithHealth(1);
}
