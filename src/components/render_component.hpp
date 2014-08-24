#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class render_component : public dawn::component
	{
	public:
		render_component(sf::Sprite& sprite, bool display_rotation = true) : sprite(sprite), display_rotation(display_rotation) {}
		sf::Sprite& sprite;
		bool display_rotation;
	};
}
