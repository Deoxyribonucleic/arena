#pragma once

#include <dawn/ecs/entity.hpp>
#include <dawn/events/event.hpp>


namespace game
{
	class death_event : public dawn::event
	{
	public:
		death_event(dawn::entity::ptr entity, dawn::entity::ptr killer)
		: entity(entity), killer(killer)
		{}

		dawn::entity::ptr entity, killer;
	};
}
