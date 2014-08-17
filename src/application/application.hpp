#pragma once

#include "game/game.hpp"

#include <SFML/Graphics.hpp>

#include <dawn/events/event_dispatcher.hpp>
#include <dawn/tasks/scheduler.hpp>


namespace game
{
	class application
	{
	public:
		application();
		~application();

		sf::RenderWindow& get_window();

		dawn::event_dispatcher& get_event_dispatcher();
		dawn::scheduler& get_scheduler();

		void run();

	private:
		sf::RenderWindow m_window;

		dawn::event_dispatcher m_event_dispatcher;
		dawn::scheduler m_scheduler;

		game m_game;
	};
}
