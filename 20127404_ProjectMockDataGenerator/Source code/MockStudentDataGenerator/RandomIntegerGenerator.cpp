#include "RandomIntegerGenerator.h"

#include <stdlib.h>
#include <time.h>
using namespace std;

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL));
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