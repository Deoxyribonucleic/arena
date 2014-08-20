#include "test_state.hpp"

#include "application/application.hpp"
#include "events/sfml_event.hpp"
#include "game/game.hpp"

#include <SFML/Window.hpp>

#include <chrono>


using namespace game;

test_state::test_state(game& game)
:
m_game(game),
m_player_factory(m_game.get_asset_loader()),
m_renderer(m_game.get_application().get_window()),
m_debug_info_system(m_game, m_game.get_application().get_window()),
m_controller_system(m_game)
{
	m_debug_info_system.set_font(m_game.get_asset_loader().get_font(fonts::base));
	m_entities.push_back(m_player_factory.create("Player 1"));


	m_game.get_event_dispatcher().add_event_handler<sfml_event>([](sfml_event const& event)
	{
		if(event.get_event().type == sf::Event::JoystickButtonPressed)
		{
			std::cout << "Dis/connected joystick" << std::endl;
		}
	});
}

test_state::~test_state()
{
}

void test_state::update(bool)
{
	m_controller_system.update(m_entities);
	m_movement_system.update(m_entities);
}

void test_state::render(bool)
{
	m_game.get_application().get_window().clear(sf::Color(180, 180, 255));

	m_renderer.update(m_entities);
	m_debug_info_system.update(m_entities);

	m_game.get_application().get_window().display();
}
