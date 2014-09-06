#pragma once

#include "assets/asset_loader.hpp"
#include "spells/elements/projectile_element.hpp"
#include "spells/elements/particle_element.hpp"
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
			glm::vec3 glm_color(color.r, color.g, color.b);

			std::unique_ptr<spell_element> ball(new projectile_element(loader, color, 1, 0));
			std::unique_ptr<spell_element> split(new projectile_element(loader, color, 2, 180));
			std::unique_ptr<spell_element> explosion(new particle_element(
				std::chrono::milliseconds(100),
				glm_color / 2.0f,
				glm_color,
				glm::vec3{40, 40, 40},
				30.f, 40.f,
				1000.f,
				360.f,
				glm::vec2{1.f, 0.f},
				400.0f,
				400.0f,
				std::chrono::milliseconds(800)));

			m_test_spell.add_spell_element(ball);
			m_test_spell.add_spell_element(split);
			m_test_spell.add_spell_element(explosion);

			//m_test_spell.get_spell_element(0).add_next_element(m_test_spell.get_spell_element(1));
			m_test_spell.get_spell_element(0).add_next_element(m_test_spell.get_spell_element(2));
			m_test_spell.get_spell_element(1).add_next_element(m_test_spell.get_spell_element(1));
			m_test_spell.get_spell_element(1).add_next_element(m_test_spell.get_spell_element(2));

			//m_ball.enable_trigger(spell_triggers::hit_player);
			//m_

			//m_test_spell.set_first_element(m_ball);
		}

		int id;

		spell m_test_spell;
	};
}
