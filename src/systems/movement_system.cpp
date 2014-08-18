#include "movement_system.hpp"

#include "components/position_component.hpp"
#include "components/movement_component.hpp"

#include <functional>
#include <iostream>


using namespace game;

movement_system::movement_system()
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<movement_component>() && entity.has_component<position_component>();
	})
{
}

void movement_system::update_entity(dawn::entity& entity)
{
	auto& position = entity.get_component<position_component>().position;
	auto& movement = entity.get_component<movement_component>();

	position += movement.velocity;

	if(glm::length(movement.velocity) != 0.0)
		movement.decelerate(movement.velocity, movement.friction);
}
