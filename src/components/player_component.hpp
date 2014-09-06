#pragma once

#include "assets/asset_loader.hpp"
#include "spells/elements/projectile_element.hpp"
#include "spells/spell.hpp"
#include "spells/spell_element.hpp"

#include <dawn/ecs/component.hpp>


namespace game
{
	class player_component : public dawn::component
	{
	public:
		player_component(int id, asset_loader& loader, sf::Color color) : id(id),
			m_ball(loader, color, 1, 0),
			m_explosion(loader, color, 36, 10)
		{
			m_ball.set_next_element(m_explosion);
			m_explosion.set_next_element(m_explosion);
			m_ball.enable_trigger(spell_triggers::hit_player);

			m_test_spell.set_first_element(m_ball);
		}

		int id;

		projectile_element m_ball, m_explosion;
		spell m_test_spell;

	};
}
