#include "RandomFloatGenerator.h"

RandomFloatGenerator::RandomFloatGenerator() {

}

float RandomFloatGenerator::next() {
	return static_cast<float>(rand()) / (static_cast <float> (RAND_MAX));
}

float RandomFloatGenerator::next(int ceiling)
{
	return static_cast<float>(rand()) / (static_cast <float> (RAND_MAX / ceiling));
}

float RandomFloatGenerator::next(int left, int right)
{
	return left + static_cast<float>(rand()) / (static_cast <float> (RAND_MAX / (right - left)));
}
