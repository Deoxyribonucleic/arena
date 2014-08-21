#include "movement_system.hpp"

#include "components/position_component.hpp"
#include "components/movement_component.hpp"
#include "game/game.hpp"

#include <functional>
#include <iostream>


using namespace game;

movement_system::movement_system(game& game)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<movement_component>() && entity->has_component<position_component>();
	}),
	m_game(game)
{
}

void movement_system::update_entity(dawn::entity::ptr entity)
{
	auto& position = entity->get_component<position_component>().position;
	auto& movement = entity->get_component<movement_component>();

	position += movement.velocity * m_game.get_delta();

	if(glm::length(movement.velocity) != 0.0)
		movement.decelerate(movement.velocity, movement.friction * m_game.get_delta());
}
