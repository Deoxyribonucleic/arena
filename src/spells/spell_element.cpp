#include "spell_element.hpp"


using namespace game;

spell_element::spell_element(spell_triggers_field spell_triggers)
: m_triggers(spell_triggers)
{

}

spell_element::~spell_element()
{

}

void spell_element::spawn_next(dawn::entity_list& entities, dawn::entity::ptr origin)
{
	for(auto element: m_next_elements)
	{
		element->spawn(entities, origin);
	}
}

void spell_element::enable_trigger(spell_trigger trigger)
{
	m_triggers = m_triggers | trigger;
}

bool spell_element::trigger_is_enabled(spell_trigger trigger)
{
	return m_triggers & trigger;
}

void spell_element::add_next_element(spell_element& element)
{
	m_next_elements.push_back(&element);
}
