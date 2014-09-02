#pragma once


namespace game
{
	class spell;
	class spell_slot
	{
	public:
		spell_slot(spell& spell);

		void set_spell(spell& spell);

	private:
		spell* m_spell;
	};
}
