#include "controller_system.hpp"

#include "components/movement_component.hpp"
#include "components/orientation_component.hpp"
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
			if(event.get_event().type == sf::Event::JoystickButtonReleased)
			{
				m_entities.add_entity(m_projectile_factory.create(entity, entity->get_component<orientation_component>().orientation));
			}
		});
}

void controller_system::update_entity(dawn::entity::ptr entity)
{
	auto& movement = entity->get_component<movement_component>();
	glm::vec2 direction;

	/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		++direction.x;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		--direction.x;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		++direction.y;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		--direction.y;*/

	direction.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100.0f;
	direction.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100.0f;


	if(glm::length(direction) != 0.0)
		movement.accelerate(direction, movement.acceleration * glm::length(direction) * m_game.get_delta(), movement.max_speed);

	// orientation
	auto& orientation = entity->get_component<orientation_component>().orientation;

	orientation.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U) / 100.0f;
	orientation.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V) / 100.0f;

	orientation = glm::normalize(orientation);
}

void controller_system::pre_update()
{
}
