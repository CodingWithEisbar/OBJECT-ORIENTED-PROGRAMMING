#ifndef _RANDOM_INTEGER_GENERATOR_H_
#define _RANDOM_INTEGER_GENERATOR_H_

#include <ctime>
#include <memory>
#include <stdlib.h>
using namespace std;

class RandomIntegerGenerator {
private:
	inline static shared_ptr<RandomIntegerGenerator> _instance = NULL;
	RandomIntegerGenerator();
public:
	static shared_ptr<RandomIntegerGenerator> instance();
public:
	int next();
	int next(int left, int right);
	int next(int ceiling);
};




#endif

