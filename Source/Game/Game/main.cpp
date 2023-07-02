#include <iostream>
#include <chrono>
#include "Core/random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include"Renderer/Renderer.h"

using namespace std;

int main()
{
	
	meow::g_memoryTracker.displayInfo();
	int* p = new int;
	meow::g_memoryTracker.displayInfo();
	delete p;
	meow::g_memoryTracker.displayInfo();

	auto start = std::chrono::high_resolution_clock::now();
	
	meow::Time timer;
	for (int i = 0; i < 1000000; i++)
	{}
		cout << timer.GetElapsedNanoseconds() << endl;
	//cout << meow::getFilePath() << endl;
	//meow::setFilePath("Assets");
	//cout << meow::getFilePath() << endl;
	//size_t size;
	//meow::getFileSize("game.txt", size);
	//cout << size << endl;

	//std::string s;
	//meow::readFile("game.txt", s);
	//cout << s << endl;


	//meow::seedRandom((unsigned int)time(nullptr));
	//for (int i = 0; i < 3; i++)
	//{
	//cout << meow::random(10,20) << endl; 
	//}

	//

}