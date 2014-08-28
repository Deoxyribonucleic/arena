#include "application.hpp"

#include "events/sfml_event.hpp"

#include <chrono>
#include <iostream>
#include <thread>


using namespace game;

application::application()
:
m_window(sf::VideoMode(1280, 800), "Project Arena"),
m_game(*this)
{
	//get_scheduler().schedule_task(std::chrono::milliseconds(1000/60),
	//	std::bind(&application::update_sfml, this), true);
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
		update_sfml();
		m_scheduler.tick();
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void application::update_sfml()
{
	sf::Event event;
	while(m_window.pollEvent(event))
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
}
