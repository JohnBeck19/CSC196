#pragma once
#include "Framework/Actor.h"

class Player : public meow::Actor
{
public:
	Player(float speed, float turnRate, const meow::Transform& transform, const std::shared_ptr<meow::Model> model) :
		Actor{ transform, model },
		m_speed{ speed },
		m_turnRate{ turnRate }
	{}
	void Update(float dt) override;
	void onCollision(Actor* actor) override;


private:
	float m_speed = 0;
	float m_turnRate = 0;

};