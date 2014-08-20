#include "game.hpp"

#include "application/application.hpp"
#include "events/sfml_event.hpp"
#include "state_stack.hpp"
#include "states/test_state.hpp"

#include <SFML/Window.hpp>

#include <chrono>


using namespace game;

game::game::game(application& app)
:
m_app(app),
m_loader("assets")
{
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::update, this), true);
	m_app.get_scheduler().schedule_task(std::chrono::seconds(1/60),
		std::bind(&game::game::render, this), true);

	m_loader.add_font(fonts::base, "fonts/UbuntuMono-Regular.ttf");

	m_loader.add_texture(textures::player, "player.png");
	m_loader.add_texture(textures::projectile, "projectile.png");

	m_loader.add_sprite(sprites::player, textures::player);
	m_loader.add_sprite(sprites::projectile, textures::projectile);

	m_loader.load();
	while(!m_loader.is_loaded())
	{
	}

	m_state_stack.push_state(std::unique_ptr<state>(new test_state(*this)));
	m_state_stack.force_stack_update();
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

asset_loader& game::game::get_asset_loader()
{
	return m_loader;
}

state_stack& game::game::get_state_stack()
{
	return m_state_stack;
}

void game::game::update()
{
	m_state_stack.update();
}

void game::game::render()
{
	m_state_stack.render();
}
