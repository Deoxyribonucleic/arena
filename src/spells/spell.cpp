#include "spell.hpp"

#include <cassert>


using namespace game;

spell::spell()
: m_first_element(nullptr)
{

}

void spell::set_first_element(spell_element& element)
{
	m_first_element = &element;
}

spell_element& spell::first()
{
	assert(m_first_element);
	return *m_first_element;
}
