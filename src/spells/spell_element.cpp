#include "spell_element.hpp"


using namespace game;

spell_element::spell_element(spell_triggers_field spell_triggers)
: m_triggers(spell_triggers), m_next_element(nullptr)
{

}

spell_element::~spell_element()
{

}

void spell_element::enable_trigger(spell_trigger trigger)
{
	m_triggers = m_triggers | trigger;
}

bool spell_element::trigger_is_enabled(spell_trigger trigger)
{
	return m_triggers & trigger;
}

spell_element* spell_element::next()
{
	return m_next_element;
}

void spell_element::set_next_element(spell_element& element)
{
	m_next_element = &element;
}
