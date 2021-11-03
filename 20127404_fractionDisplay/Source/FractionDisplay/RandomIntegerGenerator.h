#pragma once


class RandomIntegerGenerator {
public:
	RandomIntegerGenerator();
	int next(); 
	int next(int left, int right); 
	int next(int ceiling);
};