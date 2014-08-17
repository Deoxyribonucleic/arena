#pragma once

#include <dawn/ecs/system.hpp>

#include <SFML/Graphics.hpp>


namespace game
{
	class render_system : public dawn::system
	{
	public:
		render_system(sf::RenderWindow& render_target);

	protected:
		void update_entity(dawn::entity& entity);

	private:
		sf::RenderWindow& m_render_target;
	};
}
