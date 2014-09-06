#pragma once

#include "particles/particle_emitter.hpp"
#include "spells/spell_element.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>

#include <SFML/Graphics.hpp>


namespace game
{
	class particle_element : public spell_element
	{
	public:
		particle_element(
			dawn::time::duration lifetime,
			const glm::vec3& color_start,
			const glm::vec3& color_end,
			const glm::vec3& target_color,
			float size_start, float size_end,
			float frequency,
			float cone_size,
			const glm::vec2& direction,
			float speed,
			float friction,
			dawn::time::duration particle_lifetime,
			dawn::entity::ptr follow = nullptr);

		void spawn(dawn::entity_list& entities, dawn::entity::ptr origin);

	private:
		dawn::time::duration m_lifetime;
		particle_emitter m_emitter;
	};
}
