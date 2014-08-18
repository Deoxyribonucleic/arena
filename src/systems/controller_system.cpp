#include "controller_system.hpp"

#include "components/position_component.hpp"
#include "components/controller_component.hpp"

#include "game/game.hpp"

#include <SFML/Window.hpp>

#include <functional>
#include <iostream>


using namespace game;

controller_system::controller_system(game& game)
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<controller_component>() && entity.has_component<position_component>();
	})
{
	set_event_handler<sfml_event>(game.get_event_dispatcher(), std::bind(
		&controller_system::on_sfml_event,
		this, std::placeholders::_1, std::placeholders::_2));
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

void controller_system::on_sfml_event(dawn::entity& entity, const sfml_event& sfml_event)
{
	auto& event = sfml_event.get_event();

	if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	{
		entity.get_component<position_component>().x += 10;
	}
}
