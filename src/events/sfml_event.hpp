#pragma once

#include <dawn/events/event.hpp>

#include <SFML/System.hpp>


namespace game
{
	class sfml_event : public dawn::event
	{
	public:
		sfml_event(const sf::Event& event)
		: m_event(event)
		{
		}

		const sf::Event& get_event() const
		{
			return m_event;
		}

	private:
		const sf::Event& m_event;
	};
}
