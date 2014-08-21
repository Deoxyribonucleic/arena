#pragma once

#include <dawn/ecs/entity.hpp>

#include <glm/glm.hpp>

#include <string>


namespace game
{
	class asset_loader;
	class projectile_factory
	{
	public:
		projectile_factory(asset_loader& loader);

		dawn::entity::ptr create(dawn::entity::ptr shooter, glm::vec2 const& direction);

	private:
		asset_loader& m_loader;
	};
}
