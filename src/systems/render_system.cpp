#include "render_system.hpp"

#include "components/render_component.hpp"
#include "components/position_component.hpp"
#include "components/orientation_component.hpp"

#include <iostream>


using namespace game;

render_system::render_system(sf::RenderWindow& render_target)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<render_component>() && entity->has_component<position_component>();
	}),
	m_render_target(render_target)
{

}

void render_system::update_entity(dawn::entity::ptr entity)
{
	auto& sprite = entity->get_component<render_component>().sprite;
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);

	entity->get_component<render_component>().sprite.setPosition(
		entity->get_component<position_component>().position.x,
		entity->get_component<position_component>().position.y
	);

	if(entity->has_component<orientation_component>() && entity->get_component<render_component>().display_rotation)
	{
		entity->get_component<render_component>().sprite.setRotation(
			entity->get_component<orientation_component>().get_degrees()
		);
	}
	else
	{
		entity->get_component<render_component>().sprite.setRotation(0);
	}

	m_render_target.draw(entity->get_component<render_component>().sprite);
}
