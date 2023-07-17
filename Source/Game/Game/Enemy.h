#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	Enemy(float speed, float turnRate, const meow::Transform& transform, const meow::Model& model) :
		Actor{ transform, model },
		m_speed{ speed },
		m_turnRate{ turnRate }
	{}

	void Update(float dt) override;


private:
	float m_speed = 0;
	float m_turnRate = 0;

};