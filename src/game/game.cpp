#include "game.hpp"

#include "application/application.hpp"

#include <chrono>


using namespace game;

game::game::game(application& app)
:
m_app(app),
m_loader("assets"),
m_player_factory(m_loader),
m_renderer(m_app.get_window()),
m_controller_system(*this)
{
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::update, this), true);
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::render, this), true);

	m_loader.add_texture(textures::player, "player.png");
	m_loader.add_texture(textures::projectile, "projectile.png");

	m_loader.add_sprite(sprites::player, textures::player);
	m_loader.add_sprite(sprites::projectile, textures::projectile);

	m_loader.load();
	while(!m_loader.is_loaded())
	{
	}

	m_entities.push_back(m_player_factory.create("Player 1"));
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
	m_controller_system.update(m_entities);
}

void game::game::render()
{
	m_app.get_window().clear(sf::Color(180, 180, 255));

	m_renderer.update(m_entities);

	m_app.get_window().display();
}
