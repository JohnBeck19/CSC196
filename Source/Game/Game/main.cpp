#include "Input/InputSystem.h"
#include "Core/Core.h"
#include "Player.h"
#include "Enemy.h"
#include "Audio/AudioSystem.h"
#include"Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Renderer/ModelManager.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;


int main(int argc, char* argv[])
{

	

	meow::MemoryTracker::Initialize();

	//input initialization
	meow::g_inputSystem.Initialize();

	//seed randomization
	meow::seedRandom((unsigned int)time(nullptr));
	//file path
	meow::setFilePath("assets");

	//renderer initilization 
	
	meow::g_renderer.Initialize();
	meow::g_renderer.CreateWindow("MEEEEOOOOWWWWW", 500, 500);
	
	//tranform initilization 
	meow::Transform transform({400,300},0,3);
	float speed = 500;
	constexpr float turnRate = meow::DegToRad(180);
	
	//audio initilization
	
	meow::g_audioSystem.Initialize();
	meow::g_audioSystem.AddAudio("Laser", "Laser.wav");
	meow::g_audioSystem.AddAudio("Explosion", "Explosion.wav");

	//create font / text objects
	std::shared_ptr<meow::Font> font = std::make_shared<meow::Font>("space age.ttf", 24);
	std::unique_ptr<meow::Text> text = std::make_unique<meow::Text>(font);
	text->Create(meow::g_renderer, "NEUMONT", meow::Color{ 1, 1, 1, 1 });

	//std::vector<meow::vec2> points{ {-10,5},{10,5},{0,-5},{-10,5} };
	//meow::Model model{ points };
	//loading model from txt file


	//vector<meow::Vector2> points;
	//vector<Star>stars;
	//for (int i = 0; i < 1000; i++)
	//{
//		meow::Vector2 pos(meow::Vector2(meow::randomf(renderer.GetWidth()), meow::randomf(renderer.GetHeight())));
//		meow::Vector2 vel(meow::randomf(1.0f, 10.0f));

		//stars.push_back(Star(pos,vel));
	//}
	// 
	meow::Scene scene;
	unique_ptr<Player> player = make_unique<Player>(200.0f, meow::Pi, transform, meow::g_ModelManager.Get("Ship.txt"));
	player->m_tag = "Player";
	scene.Add(std::move(player));

	//players and enemies creation
	//Player player{200, meow::Pi, transform, model };
	
	//std::vector<Enemy> enemies;
	for (int i = 0; i < 10; i++) {
		unique_ptr<Enemy> enemy = make_unique<Enemy>(meow::randomf(75.0f, 150.0f), meow::Pi, meow::Transform{ {meow::random(meow::g_renderer.GetWidth()),meow::random(meow::g_renderer.GetHeight())}
		,meow::randomf(meow::TwoPi),1.5f }, meow::g_ModelManager.Get("Ship.txt"));
		//enemies.push_back(enemy);
		enemy->m_tag = "Enemy";
		scene.Add(std::move(enemy));	

	}
	
	//game loop
	bool quit = false;
	while (!quit) {
		meow::g_Time.tick();
		meow::g_inputSystem.Update();

		if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !meow::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE))
		{
			meow::g_audioSystem.PlayOneShot("Laser");
		}
		if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}

		//updates
		scene.Update(meow::g_Time.GetDeltaTime());
		


		meow::g_renderer.SetColor(0,0,0,0);
		meow::g_renderer.BeginFrame();
		meow::g_renderer.SetColor(meow::random(256), meow::random(256), meow::random(256), meow::random(256));

		//draws
		scene.Draw(meow::g_renderer);

		//text
		text->Draw(meow::g_renderer, 100, 100);
	
		
		
		//draw
		//meow::Vector2 vel(1.0f, 0.1f);

		//for (auto& star : stars) {
			//star.Update(renderer.GetWidth(),renderer.GetHeight());

			//renderer.SetColor(meow::random(256), meow::random(256), meow::random(256), meow::random(256));
			//renderer.DrawPoint(star.m_pos.x, star.m_pos.y);
		
		//}


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
		meow::g_renderer.EndFrame();

		this_thread::sleep_for(chrono::milliseconds(10));
	}
	return 0;
}
/*

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
*/
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