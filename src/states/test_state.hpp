#pragma once

#include "game/state.hpp"
#include "factories/player_factory.hpp"
#include "systems/render_system.hpp"
#include "systems/controller_system.hpp"
#include "systems/movement_system.hpp"
#include "systems/debug_info_system.hpp"


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

		std::vector<dawn::entity::ptr> m_entities;

		controller_system m_controller_system;
		debug_info_system m_debug_info_system;
		movement_system m_movement_system;
		render_system m_renderer;
	};
}
