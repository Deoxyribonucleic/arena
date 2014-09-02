#pragma once

#include "spells/spell_stage.hpp"

#include <dawn/ecs/component.hpp>


namespace game
{
	class spell_element_component : public dawn::component
	{
	public:
		spell_element_component(spell_stage& p_stage)
		: stage(p_stage)
		{

		}

		spell_stage stage;
	};
}
