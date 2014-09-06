#include "particle_render_system.hpp"

#include "components/particle_emitter_component.hpp"
#include "game/game.hpp"
#include "application/application.hpp"

#include <functional>
#include <iostream>


using namespace game;

particle_render_system::particle_render_system(game& game)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<particle_emitter_component>();
	}),
	m_game(game)
{
}

void particle_render_system::update_entity(dawn::entity::ptr entity)
{
	auto& emitter = entity->get_component<particle_emitter_component>().emitter;
	emitter.draw(m_game.get_application().get_window());
}
