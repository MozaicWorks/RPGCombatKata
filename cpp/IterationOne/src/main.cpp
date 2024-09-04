#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include "Character.h"

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::cout;
using std::endl;

int D20(){
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> dist20(1,20);
	return dist20(rng);
}

bool isCriticalHit = false;
bool isCriticalMiss = false;


int damage(){
	int damage;
	int roll = D20();
	if(roll == 1) {
		isCriticalMiss = true;
		isCriticalHit = false;
		damage = 0;
	}
	else if(roll == 20){
		isCriticalMiss = false;
		isCriticalHit = true;
		damage = 10 * roll;
	}
	else {
		isCriticalMiss = false;
		isCriticalHit = false;
		damage = 5 * roll;
	}
	return damage;
}

int main(){

	Character arthur;
	Character mordred;
	Character merlin;
	bool isHealing = true;

	while(arthur.isAlive() && mordred.isAlive()){
		int arthurDamage = damage();
		arthur.dealDamage(mordred, arthurDamage);
		if(isCriticalHit) {
			cout << "Arthur did a critical hit! ";
		}
		if(isCriticalMiss) {
			cout << "Arthur did a critical miss and won't heal! ";
			isHealing = false;
		}
		cout << "Arthur dealt " << arthurDamage << " damage to Mordred and Mordred has " << mordred.health() << " health left" << endl;
		if(!mordred.isAlive()){
			cout << "Mordred is dead! " << endl;
			break;
		}

		int mordredDamage = damage();
		mordred.dealDamage(arthur, mordredDamage);
		if(isCriticalHit) {
			cout << "Mordred did a critical hit! ";
		}
		cout << "Mordred dealt " << arthurDamage << " to Arthur and Arthur has " << arthur.health() << " health left" << endl;
		if(!arthur.isAlive()){
			cout << "Arthur is dead! " << endl;
			break;
		}

		if(isHealing){
			int merlinHealing = damage();
			merlin.heal(arthur, merlinHealing);
			cout << "Merlin healed Arthur of " << merlinHealing << " and Arthur has " << arthur.health() << " health left" << endl;
		} else{
			cout << "Merlin can't heal Arthur right now" << endl;
			isHealing = true;
		}
	}

	return 0;
}
