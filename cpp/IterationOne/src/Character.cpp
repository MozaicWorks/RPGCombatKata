#include "Character.h"

int Character::health() const{
	return myHealth;
}


int Character::isAlive() const{
	return alive;
}


int Character::level() const{
	return myLevel;
}

void Character::dealDamage(Character& defender, int damage) const {
	if(defender.health() < damage){
		defender.alive = false;
		defender.myHealth = 0;
	} else {
		defender.myHealth -= damage;
	}
}

void Character::heal(Character& patient, int healing){
	if(!patient.isAlive()){
		return;
	}
	if(patient.health() + healing > 1000){
		patient.myHealth = 1000;
	} else {
		patient.myHealth += healing;
	}
}
