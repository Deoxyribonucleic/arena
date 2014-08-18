#include "controller_system.hpp"

#include "components/position_component.hpp"
#include "components/controller_component.hpp"

#include <SFML/Window.hpp>

#include <iostream>


using namespace game;

controller_system::controller_system()
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<controller_component>() && entity.has_component<position_component>();
	})
{

}

void controller_system::update_entity(dawn::entity& entity)
{
	auto& position = entity.get_component<position_component>();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		++position.x;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		--position.x;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		++position.y;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		--position.y;
}
