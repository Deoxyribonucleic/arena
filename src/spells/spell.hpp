#pragma once

#include "spell_element.hpp"

#include <memory>


namespace game
{
	class spell
	{
	public:
		spell();
		spell_element& first();

		spell_element& get_spell_element(int index);
	 	spell_element& add_spell_element(std::unique_ptr<spell_element>& element);

	private:
		std::vector<std::unique_ptr<spell_element>> m_spell_elements;
	};
}
