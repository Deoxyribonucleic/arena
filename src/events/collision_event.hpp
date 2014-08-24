#pragma once

#include <dawn/ecs/entity.hpp>
#include <dawn/events/event.hpp>


namespace game
{
	class collision_event : public dawn::event
	{
	public:
		collision_event(dawn::entity::ptr collider, dawn::entity::ptr collidee)
		: collider(collider), collidee(collidee)
		{}

		dawn::entity::ptr collider, collidee;
	};
}
