#include "DamageCalculator.h"

DamageResult DamageCalculator::computeDamage() const {
	int roll = d20.roll();

	if(roll == 1) {
		return DamageResult{0, true, false};
	}

	if(roll == 20){
		return DamageResult{30*roll, false, true};
	}

	return DamageResult{15*roll, false, false};
}
