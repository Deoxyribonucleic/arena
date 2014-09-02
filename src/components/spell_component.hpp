#pragma once

#include "spells/spell_element.hpp"

#include <dawn/ecs/component.hpp>
#include <dawn/time.hpp>


namespace game
{
	class spell_component : public dawn::component
	{
	public:
		spell_component(spell_element& p_stage)
		: stage(p_stage)
		{

		}

		spell_element& stage;
	};
}
