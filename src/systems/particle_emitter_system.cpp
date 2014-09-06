#include "particle_emitter_system.hpp"

#include "application/application.hpp"
#include "components/position_component.hpp"
#include "components/particle_emitter_component.hpp"
#include "game/game.hpp"

#include <functional>
#include <iostream>


using namespace game;

particle_emitter_system::particle_emitter_system(game& game, particle_list& particles)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<particle_emitter_component>() && entity->has_component<position_component>();
	}),
	m_game(game), m_particles(particles)
{
}

void particle_emitter_system::update_entity(dawn::entity::ptr entity)
{
	auto& position = entity->get_component<position_component>().position;
	auto& emitter = entity->get_component<particle_emitter_component>().emitter;

	float delta = m_game.get_delta();
	emitter.update(delta, position, m_particles);
}
