#include "doctest.h"
#include "Dice.h"
#include "DamageCalculator.h"
#include "DamageAsserts.h"
#include "DiceExpectations.h"

TEST_SUITE_BEGIN("unit");

TEST_CASE("Normal damage"){
	Mock<Dice> diceStub = setDiceStubToRoll(10);
	DamageCalculator damageCalculator(diceStub.get());

	DamageResult damageResult = damageCalculator.computeDamage();

	DamageAsserts(damageResult).AssertNormalDamageIs(150);
}

TEST_CASE("Critical hit damage"){
	Mock<Dice> diceStub = setDiceStubToRoll(20);
	DamageCalculator damageCalculator(diceStub.get());

	DamageResult damageResult = damageCalculator.computeDamage();

	DamageAsserts(damageResult).AssertCriticalHit();
}

TEST_CASE("Critical miss damage"){
	Mock<Dice> diceStub = setDiceStubToRoll(1);
	DamageCalculator damageCalculator(diceStub.get());

	DamageResult damageResult = damageCalculator.computeDamage();

	DamageAsserts(damageResult).AssertCriticalMiss();
}

TEST_SUITE_END();
