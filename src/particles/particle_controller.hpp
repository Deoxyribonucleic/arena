#pragma once

#include "particle.hpp"


namespace game
{
	class particle_controller final
	{
	public:
		void update(float delta_time, particle_list& particles);
	};
}
