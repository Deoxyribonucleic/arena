#pragma once

#include "spell_triggers.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/entity_list.hpp>

#include <vector>


namespace game
{
	class spell_element
	{
	public:
		spell_element(spell_triggers_field spell_triggers);
		virtual ~spell_element();

		virtual void spawn(dawn::entity_list& entities, dawn::entity::ptr origin) = 0;
		void spawn_next(dawn::entity_list& entities, dawn::entity::ptr origin);

		void enable_trigger(spell_trigger trigger);
		bool trigger_is_enabled(spell_trigger trigger);

		void add_next_element(spell_element& element);

	protected:
		bool m_survive_trigger_count;

	private:
		std::vector<spell_element*> m_next_elements;

		spell_triggers_field m_triggers;
	};

	typedef std::vector<std::unique_ptr<spell_element>> spell_element_chain;
}
