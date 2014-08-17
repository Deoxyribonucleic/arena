#pragma once

#include <SFML/Graphics.hpp>


namespace game
{
	class application
	{
	public:
		application();
		~application();

		sf::Window& get_window();

		void run();

	private:
		sf::RenderWindow m_window;
	};
}
