#pragma once

#include <dawn/ecs/component.hpp>


namespace game
{
	class render_component : public dawn::component
	{
	public:
		render_component(sf::Sprite& sprite, bool display_rotation = true) : m_sprite(&sprite), display_rotation(display_rotation), tint(sf::Color::White) {}
		render_component(sf::Sprite& sprite, const sf::Color& p_tint, bool display_rotation = true) : m_sprite(&sprite), display_rotation(display_rotation), tint(p_tint) {}

		bool display_rotation;

		sf::Sprite& get_sprite()
		{
			return *m_sprite;
		}

		void set_sprite(sf::Sprite& sprite)
		{
			m_sprite = &sprite;
		}

		sf::Color tint;
	private:
		sf::Sprite* m_sprite;
	};
}
