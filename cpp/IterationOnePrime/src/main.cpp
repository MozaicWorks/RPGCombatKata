#include <iostream>
#include "Character.h"
#include "Dice20Faces.h"
#include "DamageCalculator.h"

using std::cout;
using std::endl;

int main(){
	Dice20Faces d20;
	DamageCalculator damageCalculator(d20);

	Character arthur;
	Character mordred;
	Character merlin;

	bool isHealing = true;

	while(arthur.isAlive() && mordred.isAlive()){
		DamageResult arthurDamage = damageCalculator.computeDamage();
		arthur.dealDamage(mordred, arthurDamage.damage);
		if(arthurDamage.isCriticalHit) {
			cout << "Arthur did a critical hit! ";
		}
		if(arthurDamage.isCriticalMiss) {
			cout << "Arthur did a critical miss and won't heal! ";
			isHealing = false;
		}
		cout << "Arthur dealt " << arthurDamage.damage << " damage to Mordred and Mordred has " << mordred.health() << " health left" << endl;
		if(!mordred.isAlive()){
			cout << "Mordred is dead! " << endl;
			break;
		}

		DamageResult mordredDamage = damageCalculator.computeDamage();
		mordred.dealDamage(arthur, mordredDamage.damage);
		if(mordredDamage.isCriticalHit) {
			cout << "Mordred did a critical hit! ";
		}
		cout << "Mordred dealt " << mordredDamage.damage << " damage to Arthur and Arthur has " << arthur.health() << " health left" << endl;
		if(!arthur.isAlive()){
			cout << "Arthur is dead! " << endl;
			break;
		}

		if(isHealing){
			DamageResult merlinHealing = damageCalculator.computeDamage();
			merlin.heal(arthur, merlinHealing.damage);
			cout << "Merlin healed Arthur of " << merlinHealing.damage << " and Arthur has " << arthur.health() << " health left" << endl;
		} else{
			cout << "Merlin can't heal Arthur right now" << endl;
			isHealing = true;
		}
	}

	return 0;
}
