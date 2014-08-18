#include "application.hpp"

#include "events/sfml_event.hpp"

#include <iostream>


using namespace game;

application::application()
:
m_window(sf::VideoMode(1280, 800), "Project Arena"),
m_game(*this)
{

}

application::~application()
{

}

sf::RenderWindow& application::get_window()
{
	return m_window;
}

dawn::event_dispatcher& application::get_event_dispatcher()
{
	return m_event_dispatcher;
}

dawn::scheduler& application::get_scheduler()
{
	return m_scheduler;
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
			else
			{
				m_event_dispatcher.notify(sfml_event(event));
			}
		}

		m_scheduler.tick();
	}
}
