#include "debug_info_system.hpp"

#include "components/player_component.hpp"
#include "components/position_component.hpp"
#include "game/game.hpp"

#include <iostream>
#include <string>


using namespace game;

debug_info_system::debug_info_system(game& game, sf::RenderWindow& render_target)
: dawn::system([](dawn::entity& entity)
	{
		return entity.has_component<player_component>() && entity.has_component<position_component>();
	}),
	m_render_target(render_target), m_font(nullptr)
{
	m_text.setCharacterSize(24);
	m_text.setColor(sf::Color(0, 0, 0));
	m_text.setStyle(sf::Text::Regular);
}

void debug_info_system::update_entity(dawn::entity& entity)
{
	auto& position = entity.get_component<position_component>().position;
	int playerNumber = entity.get_component<player_component>().id;

	m_text.setString("Player #" + std::to_string(playerNumber) + " position: " + std::to_string(position.x) + ", " + std::to_string(position.y));
	m_text.setPosition(10, m_text_y);
	m_render_target.draw(m_text);

	m_text_y += m_font->getLineSpacing(24);
}

void debug_info_system::pre_update()
{
	m_text_y = 10;
}

void debug_info_system::set_font(sf::Font& font)
{
	m_font = &font;
	m_text.setFont(font);
}
