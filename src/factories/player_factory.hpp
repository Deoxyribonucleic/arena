#pragma once

#include "util/math.hpp"

#include <dawn/ecs/entity.hpp>

#include <string>


namespace game
{
	class asset_loader;
	class player_factory
	{
	public:
		player_factory(asset_loader& loader);

		dawn::entity::ptr create(int number, int controller_id, const glm::vec2& position);

	private:
		asset_loader& m_loader;
	};
}
