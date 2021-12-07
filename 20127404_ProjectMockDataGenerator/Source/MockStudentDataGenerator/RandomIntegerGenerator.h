#ifndef _INTEGERANDOM_H_
#define _INTEGERANDOM_H_

class RandomIntegerGenerator {
public:
	RandomIntegerGenerator();
	int next(); 
	int next(int left, int right); 
	int next(int ceiling);
};

#endif