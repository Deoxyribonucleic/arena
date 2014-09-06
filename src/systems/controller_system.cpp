#include "controller_system.hpp"

#include "components/movement_component.hpp"
#include "components/orientation_component.hpp"
#include "components/player_component.hpp"
#include "components/controller_component.hpp"
#include "events/sfml_event.hpp"
#include "game/game.hpp"

#include <SFML/Window.hpp>

#include <glm/glm.hpp>

#include <functional>
#include <iostream>


using namespace game;

controller_system::controller_system(game& game, dawn::entity_list& entities)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<controller_component>() && entity->has_component<movement_component>() && entity->has_component<orientation_component>();
	}),
	m_game(game),
	m_entities(entities),
	m_projectile_factory(m_game.get_asset_loader())
{
	set_event_handler<sfml_event>(m_game.get_event_dispatcher(), [this](dawn::entity::ptr entity, sfml_event const& event)
		{
			auto& player = entity->get_component<player_component>();

			if(event.get_event().type == sf::Event::JoystickButtonReleased && event.get_event().joystickButton.joystickId == entity->get_component<controller_component>().controller_id)
			{
				//m_entities.add_entity(m_projectile_factory.create(entity, entity->get_component<orientation_component>().orientation));
				player.m_test_spell.first().spawn(m_entities, entity);
			}
		});
}

void controller_system::update_entity(dawn::entity::ptr entity)
{
	int controller_id = entity->get_component<controller_component>().controller_id;

	auto& movement = entity->get_component<movement_component>();
	glm::vec2 direction;

	direction.x = sf::Joystick::getAxisPosition(controller_id, sf::Joystick::Axis::X) / 100.0f;
	direction.y = sf::Joystick::getAxisPosition(controller_id, sf::Joystick::Axis::Y) / 100.0f;

	if(glm::length(direction) != 0.0)
		movement.accelerate(direction, movement.acceleration * glm::length(direction) * m_game.get_delta(), movement.max_speed);

	// orientation
	auto& orientation = entity->get_component<orientation_component>().orientation;
	glm::vec2 new_orientation;

	new_orientation.x = sf::Joystick::getAxisPosition(controller_id, sf::Joystick::Axis::U) / 100.0f;
	new_orientation.y = sf::Joystick::getAxisPosition(controller_id, sf::Joystick::Axis::V) / 100.0f;

	// only change aim if stick movement is more than 10%, so that it doesn't revert if the stick is released
	if(glm::length(new_orientation) > 0.1f)
		orientation = glm::normalize(new_orientation);
}

void controller_system::pre_update()
{
}
