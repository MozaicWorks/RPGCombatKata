#include "DamageCalculator.h"
#include "doctest.h"

#pragma once
class DamageAsserts{
	private:
		const DamageResult& result;

	public:
		DamageAsserts(const DamageResult& result) : result(result){}

		void AssertCriticalHit(){
			CHECK_EQ(600, result.damage);
			CHECK_EQ(true, result.isCriticalHit);
			CHECK_EQ(false, result.isCriticalMiss);
		}

		void AssertCriticalMiss(){
			CHECK_EQ(0, result.damage);
			CHECK_EQ(false, result.isCriticalHit);
			CHECK_EQ(true, result.isCriticalMiss);
		}

		void AssertNormalDamageIs(const int damage){
			CHECK_EQ(damage, result.damage);
			CHECK_EQ(false, result.isCriticalHit);
			CHECK_EQ(false, result.isCriticalMiss);
		}
};
