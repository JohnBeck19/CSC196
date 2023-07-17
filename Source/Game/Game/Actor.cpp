#include "Actor.h"

void Actor::Draw(meow::Renderer& renderer)
{
	m_model.Draw(renderer, m_transform);

}
