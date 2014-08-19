#pragma once

#include <dawn/ecs/system.hpp>

#include <SFML/Graphics.hpp>


namespace game
{
	class game;
	class debug_info_system : public dawn::system
	{
	public:
		debug_info_system(game& game, sf::RenderWindow& render_target);

		void set_font(sf::Font& font);

	protected:
		void update_entity(dawn::entity& entity);

		void pre_update();

	private:
		sf::RenderWindow& m_render_target;

		int m_text_y;
		sf::Font* m_font;
		sf::Text m_text;
	};
}
