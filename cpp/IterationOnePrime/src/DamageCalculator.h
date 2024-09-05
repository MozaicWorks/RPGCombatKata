#pragma once
#include "Dice20Faces.h"

struct DamageResult{
	int damage;
	bool isCriticalMiss;
	bool isCriticalHit;
};

class DamageCalculator{
	private:
		const Dice20Faces& d20;

	public:
		DamageCalculator(const Dice20Faces& d20) : d20(d20){}

		DamageResult computeDamage() const;
};
