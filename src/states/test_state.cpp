#include "test_state.hpp"

#include "application/application.hpp"
#include "events/death_event.hpp"
#include "events/collision_event.hpp"
#include "game/game.hpp"

#include <components/bounding_box_component.hpp>
#include <components/position_component.hpp>
#include <components/render_component.hpp>
#include <components/controller_component.hpp>
#include <components/health_component.hpp>

#include <SFML/Window.hpp>

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
m_despawn_system(m_entities)
{
	m_debug_info_system.set_font(m_game.get_asset_loader().get_font(fonts::base));
	m_entities.add_entity(m_player_factory.create(1, 0));
	m_entities.add_entity(m_player_factory.create(2, 1));

	dawn::entity::ptr obstacle = std::make_shared<dawn::entity>();
	obstacle->add_component<position_component>(glm::vec2(400, 250));
	obstacle->add_component<render_component>(m_game.get_asset_loader().get_sprite(sprites::obstacle_red));
	obstacle->add_component<bounding_box_component>(64, 128);
	obstacle->add_component<health_component>(20);
	m_entities.add_entity(obstacle);

	m_game.get_event_dispatcher().add_event_handler<collision_event>([this](const collision_event& event)
	{
		std::cout << "collision occurred!" << std::endl;

		// despawn projectile
		m_entities.remove_entity(event.collider);

		// decrease health of hit object
		if(event.collidee->has_component<health_component>())
		{
			event.collidee->get_component<health_component>().health -= 5;
		}
	});

	m_game.get_event_dispatcher().add_event_handler<death_event>([this](const death_event& event)
	{
		std::cout << "death occurred!" << std::endl;

		if(event.entity->has_component<bounding_box_component>() && event.entity->has_component<render_component>())
		{
			event.entity->remove_component<bounding_box_component>();
			event.entity->remove_component<health_component>();

			event.entity->get_component<render_component>().set_sprite(m_game.get_asset_loader().get_sprite(sprites::obstacle_black));
		}
	});
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
}

void test_state::render(bool)
{
	m_game.get_application().get_window().clear(sf::Color(180, 180, 255));

	m_renderer.update(m_entities);
	m_debug_info_system.update(m_entities);

	m_game.get_application().get_window().display();
}
