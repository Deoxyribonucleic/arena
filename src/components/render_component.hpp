#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class render_component : public dawn::component
	{
	public:
		render_component(sf::Sprite& sprite) : sprite(sprite) {}
		sf::Sprite& sprite;
	};
}
