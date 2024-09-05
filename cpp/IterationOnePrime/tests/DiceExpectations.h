#include "fakeit.hpp"

using fakeit::Mock;
using fakeit::When;

#pragma once

Mock<Dice> setDiceStubToRoll(const int value){
	Mock<Dice> diceStub;
	When(Method(diceStub, roll)).Return(value);
	return diceStub;
}
