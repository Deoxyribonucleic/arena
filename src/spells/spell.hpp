#pragma once

#include "spell_element.hpp"

#include <memory>


namespace game
{
	class spell
	{
	public:
		spell();
		void set_first_element(spell_element& element);

		spell_element& first();

	private:
		spell_element* m_first_element;
	};
}
