#include "controller_system.hpp"

#include "components/movement_component.hpp"
#include "components/controller_component.hpp"

#include "game/game.hpp"

#include <glm/glm.hpp>

#include <functional>
#include <iostream>


using namespace game;

controller_system::controller_system(game& game)
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<controller_component>() && entity.has_component<movement_component>();
	})
{
}

void controller_system::update_entity(dawn::entity& entity)
{
	auto& movement = entity.get_component<movement_component>();
	glm::vec2 direction;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		++direction.x;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		--direction.x;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		++direction.y;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		--direction.y;

	if(glm::length(direction) != 0.0)
		movement.accelerate(direction);
}
