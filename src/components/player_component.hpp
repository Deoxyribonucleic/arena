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
		player_component(int id, asset_loader& loader, sf::Color color) : id(id)
		{
			std::unique_ptr<spell_element> ball(new projectile_element(loader, color, 1, 0));
			std::unique_ptr<spell_element> explosion(new projectile_element(loader, color, 2, 180));

			m_test_spell.add_spell_element(ball);
			m_test_spell.add_spell_element(explosion);

			m_test_spell.get_spell_element(0).add_next_element(m_test_spell.get_spell_element(1));
			m_test_spell.get_spell_element(1).add_next_element(m_test_spell.get_spell_element(1));

			//m_ball.enable_trigger(spell_triggers::hit_player);
			//m_

			//m_test_spell.set_first_element(m_ball);
		}

		int id;

		spell m_test_spell;
	};
}
