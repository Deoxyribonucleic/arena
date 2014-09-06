#include "test_state.hpp"

#include "application/application.hpp"
#include "events/death_event.hpp"
#include "events/collision_event.hpp"
#include "game/game.hpp"
#include "events/sfml_event.hpp"

#include <components/bounding_box_component.hpp>
#include <components/position_component.hpp>
#include <components/render_component.hpp>
#include <components/controller_component.hpp>
#include <components/health_component.hpp>
#include <components/spell_component.hpp>

#include <SFML/Window.hpp>

#include <glm/glm.hpp>

#include <chrono>


using namespace game;

test_state::test_state(game& game)
:
m_game(game),
m_player_factory(m_game.get_asset_loader()),
m_renderer(m_game.get_application().get_window()),
m_death_system(m_game, m_entities),
m_debug_info_system(m_game, m_game.get_application().get_window()),
m_collision_system(m_game, m_entities),
m_controller_system(m_game, m_entities),
m_movement_system(m_game),
m_despawn_system(m_entities),
m_spell_system(m_game, m_entities),
m_particle_render_system(m_game),
m_particle_system(m_game),
m_player_system(m_game, m_entities),
m_projectile_system(m_game, m_entities)
{
	m_debug_info_system.set_font(m_game.get_asset_loader().get_font(fonts::base));

	auto player = m_player_factory.create(1, 0, glm::vec2(400, 400));
	m_entities.add_entity(player);
	m_entities.add_entity(m_player_factory.create(2, 1, glm::vec2(900, 400)));

	/*m_game.get_event_dispatcher().add_event_handler<sfml_event>([this, player](const sfml_event& event)
	{
		if(event.get_event().type == sf::Event::KeyReleased)
			m_test_spell.first().spawn(m_entities, player);
	});*/
}

test_state::~test_state()
{
}

void test_state::update(bool)
{
	m_despawn_system.update(m_entities);
	m_controller_system.update(m_entities);
	m_movement_system.update(m_entities);
	m_collision_system.update(m_entities);
	m_death_system.update(m_entities);
	m_particle_system.update(m_entities);
	m_player_system.update(m_entities);
	m_projectile_system.update(m_entities);
	m_spell_system.update(m_entities);
}

void test_state::render(bool)
{
	m_game.get_application().get_window().clear(sf::Color(40, 40, 40));

	m_particle_render_system.update(m_entities);
	m_renderer.update(m_entities);
	m_debug_info_system.update(m_entities);

	m_game.get_application().get_window().display();
}
