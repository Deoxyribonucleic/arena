#include "render_system.hpp"

#include "components/render_component.hpp"
#include "components/position_component.hpp"

#include <iostream>


using namespace game;

render_system::render_system(sf::RenderWindow& render_target)
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<render_component>() && entity.has_component<position_component>();
	}),
	m_render_target(render_target)
{

}

void render_system::update_entity(dawn::entity& entity)
{
	entity.get_component<render_component>().sprite.setPosition(
		entity.get_component<position_component>().x,
		entity.get_component<position_component>().y
	);

	m_render_target.draw(entity.get_component<render_component>().sprite);
}
