#include "spell.hpp"

#include <cassert>


using namespace game;

spell::spell()
{

}

spell_element& spell::get_spell_element(int index)
{
	assert(m_spell_elements.size() > index);
	return *m_spell_elements[index];
}

spell_element& spell::add_spell_element(std::unique_ptr<spell_element>& element)
{
	assert(element);
	spell_element& element_ref = *element;
	m_spell_elements.push_back(std::move(element));

	return element_ref;
}

spell_element& spell::first()
{
	assert(m_spell_elements.size() != 0);
	return *m_spell_elements[0];
}
