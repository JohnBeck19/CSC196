#include <iostream>
#include "Core/random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"

using namespace std;

int main()
{
	int* p = new int;

	delete p;
	


	cout << meow::getFilePath() << endl;
	meow::setFilePath("Assets");
	cout << meow::getFilePath() << endl;
	size_t size;
	meow::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	meow::readFile("game.txt", s);
	cout << s << endl;


	meow::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 3; i++)
	{
	cout << meow::random(10,20) << endl; 
	}

	

}