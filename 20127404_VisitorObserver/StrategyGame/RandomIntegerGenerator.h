#ifndef _RANDOM_INTEGER_GENERATOR_H_
#define _RANDOM_INTEGER_GENERATOR_H_

#include <ctime>
#include <stdlib.h>
using namespace std;

class RandomIntegerGenerator {
private:
	inline static RandomIntegerGenerator* _instance = NULL;
	RandomIntegerGenerator();
public:
	static RandomIntegerGenerator* instance();
public:
	int next();
	int next(int left, int right);
	int next(int ceiling);
};




#endif

