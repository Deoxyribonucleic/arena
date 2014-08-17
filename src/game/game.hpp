#pragma once

#include <dawn/events/event_dispatcher.hpp>
#include <dawn/tasks/scheduler.hpp>


namespace game
{
	class application;
	class game
	{
	public:
		game(application& app);
		~game();

		dawn::event_dispatcher& get_event_dispatcher();
		dawn::scheduler& get_scheduler();

		application& get_application();

		void update();
		void render();

	private:
		application& m_app;


	};
}
