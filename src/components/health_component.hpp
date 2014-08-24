#pragma once

#include <dawn/ecs/component.hpp>
#include <dawn/time.hpp>


namespace game
{
	class health_component : public dawn::component
	{
	public:
		health_component(int max_health)
		: max_health(max_health), health(max_health)
		{
		}

		inline bool is_alive() const
		{
			return health > 0;
		}

		int max_health;
		int health;
	};
}
