#include "RandomIntegerGenerator.h"

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL)); 
}

RandomIntegerGenerator* RandomIntegerGenerator::instance()
{
	if (_instance == NULL)
	{
		_instance = new RandomIntegerGenerator();
	}
	return  _instance;
}

int RandomIntegerGenerator::next() {
	return rand();
}

int RandomIntegerGenerator::next(int left, int right) {
	//Return a random number in range [left,right];
	return rand() % (right - left + 1) + left;
}

int RandomIntegerGenerator::next(int ceiling) {
	return rand() % ceiling;
}