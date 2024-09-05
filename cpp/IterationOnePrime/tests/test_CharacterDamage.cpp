#include <vector>
#include "doctest.h"
#include "Character.h"
#include "CharacterAsserts.h"
#include "CharacterBuilder.h"

using std::vector;


void repeatDamage(const Character& attacker, Character& defender, vector<int> damages){
	for(int theDamage : damages){
		attacker.dealDamage(defender, theDamage);
	}
}

TEST_SUITE_BEGIN("unit");

TEST_CASE("Defender's health decreases after an attacker deals damage"){
	int defenderInitialHealth;
	int damage;
	int expectedHealth;

	SUBCASE("Damage 1 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 1;
		expectedHealth = 999;
	}
	SUBCASE("Damage 200 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 200;
		expectedHealth = 800;
	}
	SUBCASE("Damage 999 To Full Health"){
		defenderInitialHealth = 1000;
		damage = 999;
		expectedHealth = 1;
	}
	SUBCASE("Damage 998 To Health 999"){
		defenderInitialHealth = 999;
		damage = 998;
		expectedHealth = 1;
	}
	SUBCASE("Damage 1 To Health 2"){
		defenderInitialHealth = 2;
		damage = 1;
		expectedHealth = 1;
	}

	CAPTURE(defenderInitialHealth);
	CAPTURE(damage);
	CAPTURE(expectedHealth);

	Character attacker;
	Character defender = CharacterBuilder::aCharacter().aliveWithHealth(defenderInitialHealth).build();

	attacker.dealDamage(defender, damage);

	CharacterAsserts(defender).isAlive();
	CharacterAsserts(defender).hasHealth(expectedHealth);
}

TEST_CASE("Defender dies and health goes to 0 when damage higher than health"){
	Character attacker;
	Character defender;
	vector<int> damages;

	SUBCASE("Damage 1001"){
		damages = {1001};
	}
	SUBCASE("Subsequent attacks total damage 1001"){
		damages = {10, 133, 234, 77, 14, 320, 213 };
	}

	SUBCASE("Damage 1100"){
		damages = {1100};
	}
	CAPTURE(damages);

	repeatDamage(attacker, defender, damages);

	CharacterAsserts(defender).isDead();
}

TEST_SUITE_END();
