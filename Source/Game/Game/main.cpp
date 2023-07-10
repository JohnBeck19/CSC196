#include <iostream>
#include <chrono>
#include "Core/Core.h"
#include"Renderer/Renderer.h"
#include <vector>


using namespace std;

class Star {

public:
	Star(const meow::Vector2& pos, const meow::Vector2& vel) : m_pos{ pos }, m_vel{ vel } {}

	void Update(int width, int height) {
		m_pos += m_vel;

		if (m_pos.x > width) {
			m_pos.x = 0;
		}
		if (m_pos.y > height) {
			m_pos.y = 0;
		}
	}

public:
	meow::Vector2 m_pos;
	meow::Vector2 m_vel;

};



int main(int argc, char* argv[])
{
	meow::seedRandom((unsigned int) time(nullptr));

	
	meow::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("MEEEEOOOOWWWWW",500,500);


	vector<meow::Vector2> points;
	vector<Star> stars;
	for (int i = 0; i < 1000; i++)
	{
		meow::Vector2 pos(meow::Vector2(meow::randomf(renderer.GetWidth()), meow::randomf(renderer.GetHeight())));
		meow::Vector2 vel(meow::randomf(1.0f, 10.0f));

		stars.push_back(Star(pos,vel));
	}
	while (true) {
		renderer.SetColor(0,0,0,0);
		renderer.BeginFrame();
		//draw
		meow::Vector2 vel(1.0f, 0.1f);

		for (auto& star : stars) {
			star.Update(renderer.GetWidth(),renderer.GetHeight());

			renderer.SetColor(meow::random(256), meow::random(256), meow::random(256), meow::random(256));
			renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		
		}


		//for (int i = 0; i < 100; i++)
		//{
		//	meow::Vector2 pos(meow::randomf(renderer.GetWidth()), meow::randomf(renderer.GetHeight()));

		//	renderer.SetColor(meow::random(256), meow::random(256), meow::random(256), meow::random(256));
		//	renderer.DrawPoint(pos.x, pos.y);
		//	//renderer.DrawLine(pos.x, pos.y,10.0,10.0);
		//	//renderer.DrawPoint(meow::random(renderer.GetWidth()), meow::random(renderer.GetHeight()));
		//	//renderer.DrawLine(meow::random(renderer.GetWidth()), meow::random(renderer.GetHeight()),
		//		//meow::random(renderer.GetWidth()), meow::random(renderer.GetHeight()));
		//}

		//draw
		renderer.EndFrame();

	}
}
/*

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
*/