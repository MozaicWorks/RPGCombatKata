#include "Dice20Faces.h"
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


int Dice20Faces::roll() const {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> dist20(1,20);
	return dist20(rng);
}
