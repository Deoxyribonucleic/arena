#pragma once

#include <dawn/ecs/component.hpp>
#include <dawn/time.hpp>


namespace game
{
	class lifetime_component : public dawn::component
	{
	public:
		lifetime_component(dawn::time::duration lifetime)
		: lifetime(lifetime)
		{
			reset();
		}

		void reset()
		{
			spawn_time = dawn::time::clock::now();
		}

		dawn::time::time_point spawn_time;
		dawn::time::duration lifetime;
	};
}
