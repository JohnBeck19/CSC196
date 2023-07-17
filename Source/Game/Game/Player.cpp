#include "Player.h"
#include "Input/InputSystem.h"
void Player::Update(float dt)
{
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
}
