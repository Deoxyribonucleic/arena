#pragma once

#include <dawn/ecs/system.hpp>
#include <dawn/time.hpp>

#include <SFML/Graphics.hpp>

#include <chrono>


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
		void print_line(std::string const& string);

		sf::RenderWindow& m_render_target;

		int m_text_y;
		sf::Font* m_font;
		sf::Text m_text;

		int m_fps;
		int m_frames_this_second;
		dawn::time::time_point m_last_fps_update_time;
	};
}
