#pragma once

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>

#include <vector>


namespace game
{
	class spell_element
	{
	public:
		virtual ~spell_element();

		void spawn(dawn::entity_list& entities);
	};
	typedef std::vector<std::unique<spell_element>> spell_element_chain;
}
