#pragma once


namespace game
{
	class state
	{
	public:
		state();
		virtual ~state();

		virtual void update(bool top) = 0;
		virtual void render(bool top) = 0;
	};
}
