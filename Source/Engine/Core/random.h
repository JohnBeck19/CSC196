#pragma once
#include<random>

namespace meow
{
	void seedRandom(unsigned int seed) { srand(seed); }
	int random() { return rand(); }
	int random(unsigned int max) { return rand() % max; }//return between 0 and 1 less than max
	int random(unsigned int min, unsigned int max) { return min + random(max - min + 1); } //return numbers in between min and max inclusive

	float randomf() { return random() / (float)RAND_MAX; };
	float randomf(float max) { return randomf() * max; };
	float randomf(float min, float max) { return min + randomf() * (max - min); };

}