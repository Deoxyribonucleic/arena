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
	auto& sprite = entity->get_component<render_component>().get_sprite();
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
	sprite.setColor(entity->get_component<render_component>().tint);

	sprite.setPosition(
		entity->get_component<position_component>().position.x,
		entity->get_component<position_component>().position.y
	);

	if(entity->has_component<orientation_component>() && entity->get_component<render_component>().display_rotation)
	{
		sprite.setRotation(
			entity->get_component<orientation_component>().get_degrees()
		);
	}
	else
	{
		sprite.setRotation(0);
	}

	m_render_target.draw(sprite);
}
