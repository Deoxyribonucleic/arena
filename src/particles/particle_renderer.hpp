#pragma once

#include "particle.hpp"

#include <SFML/Graphics.hpp>


namespace game
{
	class particle_renderer final
	{
	public:
		particle_renderer();

		void render(sf::RenderWindow& render_target, const particle_list& particles);

	private:
		sf::RectangleShape m_shape;
	};
}
