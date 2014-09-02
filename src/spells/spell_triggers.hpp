#pragma once

#include <cstdint>


namespace game
{
	typedef uint8_t spell_trigger;
	typedef spell_trigger spell_triggers_field;
	namespace spell_triggers
	{
		const spell_trigger hit_player   = 1 << 0,
		                    hit_obstacle = 1 << 1,
		                    lifetime     = 1 << 2,
		                    range        = 1 << 3,
		                    reactivate   = 1 << 4;
	}
}
