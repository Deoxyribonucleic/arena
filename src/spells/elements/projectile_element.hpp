#pragma once

#include "spells/spell_element.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>

#include <SFML/Graphics.hpp>


namespace game
{
	class asset_loader;
	class projectile_element : public spell_element
	{
	public:
		projectile_element(asset_loader& loader, const sf::Color& color, int count, float spread);

		void spawn(dawn::entity_list& entities, dawn::entity::ptr origin);

	private:
		asset_loader& m_loader;
		int m_count;
		float m_spread;
		sf::Color m_color;
	};
}
