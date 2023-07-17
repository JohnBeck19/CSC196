#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"
class Actor
{
public:
	Actor() = default;
	Actor(const meow::Transform& transform, const meow::Model& model) :
		m_transform{ transform },
		m_model{ model }
	{}

	virtual void Update(float dt) = 0;
	virtual void Draw(meow::Renderer& renderer);

protected:

	meow::Transform m_transform;
	meow::Model m_model;




};