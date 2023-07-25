#include "Player.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Bullet.h"
void Player::Update(float dt)
{
	//movement
	float rotate = 0;
	if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
	if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
	m_transform.rotation += rotate * m_turnRate * dt;

	float thrust = 0;
	if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;

	meow::Vector2 forward = meow::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * dt;
	m_transform.position.x = meow::Wrap(m_transform.position.x, (float)meow::g_renderer.GetWidth());
	m_transform.position.y = meow::Wrap(m_transform.position.y, (float)meow::g_renderer.GetHeight());


	//fire
	
	if (meow::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !meow::g_inputSystem.GetPreviousKeyDown(SDL_SCANCODE_SPACE))
	{
		meow::Transform transform{ m_transform.position,m_transform.rotation,1 };
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>( 400.0f,transform,m_model);
		bullet->m_tag = "Player";
		m_scene->Add(std::move(bullet));
	}
}

void Player::onCollision(Actor* other)
{
	if (other->m_tag != m_tag) {
		m_destroyed = true;
	}
}
