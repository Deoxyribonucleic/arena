#include "application.hpp"

#include <iostream>


using namespace game;

application::application()
: m_window(sf::VideoMode(800, 600), "Project Arena")
{

}

application::~application()
{

}

sf::Window& application::get_window()
{
	return m_window;
}

void application::run()
{
	while(m_window.isOpen())
	{
		sf::Event event;
		if(m_window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		m_window.clear();
		m_window.display();
	}
}
