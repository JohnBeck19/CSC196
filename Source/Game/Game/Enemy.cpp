#include "Enemy.h"
#include "Renderer/Renderer.h"
void Enemy::Update(float dt)
{
	

	meow::Vector2 forward = meow::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * 1 * dt;
	m_transform.position.x = meow::Wrap(m_transform.position.x, (float)meow::g_renderer.GetWidth());
	m_transform.position.y = meow::Wrap(m_transform.position.y, (float)meow::g_renderer.GetHeight());
}