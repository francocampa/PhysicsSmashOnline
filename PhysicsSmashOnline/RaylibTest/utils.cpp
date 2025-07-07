#include "utils.h"
#include <random>

float getRandomFloat(float min, float max)
{
	if (min >= max) {
		std::swap(min, max);
	}
	static std::random_device rd;  
	static std::mt19937 gen(rd()); // Mersenne Twister engine
	std::uniform_real_distribution<float> dist(min, max);
	return dist(gen);
}
