#include "Enemy.h"
#include "Renderer/Renderer.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Bullet.h"

void Enemy::Update(float dt)
{
	Actor::Update(dt);

	Player* player = m_scene->GetActor<Player>();
	if (player) {
		meow::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.Angle() + meow::HalfPi;

	}

	meow::Vector2 forward = meow::vec2{ 0,-1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * 1 * dt;
	m_transform.position.x = meow::Wrap(m_transform.position.x, (float)meow::g_renderer.GetWidth());
	m_transform.position.y = meow::Wrap(m_transform.position.y, (float)meow::g_renderer.GetHeight());

	if (m_fireTimer <= 0) {
		meow::Transform transform{ m_transform.position,m_transform.rotation,1 };
		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(400.0f, transform, m_model);
		bullet->m_tag = "Enemy";
		m_scene->Add(std::move(bullet));
		m_fireTimer = m_fireRate;
	}
	else {
		m_fireTimer -= dt;
		
	}
}

void Enemy::onCollision(Actor* other)
{
	if (other->m_tag != m_tag) {
		m_destroyed = true;
	}
}
