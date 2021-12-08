#ifndef _FLOATRANDOM_H_
#define _FLOATRANDOM_H_
#include <ctime>
#include <cstdlib>

class RandomFloatGenerator {
public:
	RandomFloatGenerator();
	
public:
	float next();

	float next(int ceiling);

	float next(int left, int right);
};

#endif