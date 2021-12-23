#include "randomIntegerGenerator.h"

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL)); 
}

shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::instance()
{
	if (_instance == NULL)
	{
		RandomIntegerGenerator* temp = new RandomIntegerGenerator();
		_instance = make_shared<RandomIntegerGenerator>(*temp);
	}
	return _instance;
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