#include "game.hpp"

#include "application/application.hpp"

#include <chrono>


using namespace game;

game::game::game(application& app)
: m_app(app)
{
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::update, this), true);
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::render, this), true);
}

game::game::~game()
{

}

dawn::event_dispatcher& game::game::get_event_dispatcher()
{
	return m_app.get_event_dispatcher();
}

dawn::scheduler& game::game::get_scheduler()
{
	return m_app.get_scheduler();
}

application& game::game::get_application()
{
	return m_app;
}

void game::game::update()
{
}

void game::game::render()
{
	m_app.get_window().clear(sf::Color(255, 0, 0));
	m_app.get_window().display();
}
