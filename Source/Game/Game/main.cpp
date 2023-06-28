#include <iostream>
#include "Core/random.h"
#include "Core/FileIO.h"


using namespace std;
int main()
{
	meow::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++)
	{
	cout << meow::random(10,20) << endl; 
	}

	cout << meow::getFilePath();

}