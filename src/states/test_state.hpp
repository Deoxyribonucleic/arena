#pragma once

#include "game/state.hpp"
#include "spells/elements/projectile_element.hpp"
#include "spells/spell.hpp"
#include "spells/spell_element.hpp"
#include "factories/player_factory.hpp"
#include "systems/render_system.hpp"
#include "systems/collision_system.hpp"
#include "systems/controller_system.hpp"
#include "systems/movement_system.hpp"
#include "systems/debug_info_system.hpp"
#include "systems/despawn_system.hpp"
#include "systems/death_system.hpp"
#include "systems/spell_system.hpp"
#include "systems/particle_render_system.hpp"
#include "systems/particle_system.hpp"
#include "systems/player_system.hpp"
#include "systems/projectile_system.hpp"

#include <dawn/ecs/entity_list.hpp>


namespace game
{
	class game;
	class test_state : public state
	{
	public:
		test_state(game& game);
		~test_state();

		void update(bool top);
		void render(bool top);

	private:
		game& m_game;

		player_factory m_player_factory;

		dawn::entity_list m_entities;

		collision_system m_collision_system;
		controller_system m_controller_system;
		death_system m_death_system;
		debug_info_system m_debug_info_system;
		despawn_system m_despawn_system;
		movement_system m_movement_system;
		render_system m_renderer;
		particle_render_system m_particle_render_system;
		particle_system m_particle_system;
		player_system m_player_system;
		projectile_system m_projectile_system;
		spell_system m_spell_system;
	};
}
