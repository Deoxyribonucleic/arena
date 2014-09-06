#include "debug_info_system.hpp"

#include "components/player_component.hpp"
#include "components/position_component.hpp"
#include "components/health_component.hpp"
#include "components/orientation_component.hpp"
#include "game/game.hpp"

#include <iostream>
#include <string>


using namespace game;

debug_info_system::debug_info_system(game& game, sf::RenderWindow& render_target)
: dawn::system([](dawn::entity::ptr entity)
	{
		return entity->has_component<player_component>() && entity->has_component<position_component>();
	}),
	m_render_target(render_target), m_font(nullptr),
	m_fps(0),
	m_frames_this_second(0),
	m_last_fps_update_time(dawn::time::clock::now())
{
	m_text.setCharacterSize(24);
	m_text.setColor(sf::Color(0, 0, 0));
	m_text.setStyle(sf::Text::Regular);
}

void debug_info_system::update_entity(dawn::entity::ptr entity)
{
	auto& position = entity->get_component<position_component>().position;
	int player_number = entity->get_component<player_component>().id;
	auto& orientation = entity->get_component<orientation_component>();
	int player_health = entity->get_component<health_component>().health;

	print_line("Player #" + std::to_string(player_number) + " - " + std::to_string(player_health) + " HP");
	print_line(" * position: " + std::to_string(position.x) + ", " + std::to_string(position.y));
	print_line(" * orientation: " + std::to_string(orientation.get_degrees()));
}

void debug_info_system::pre_update()
{
	++m_frames_this_second;
	auto now = dawn::time::clock::now();
	if(now - m_last_fps_update_time > std::chrono::seconds(1))
	{
		m_fps = m_frames_this_second;
		m_frames_this_second = 0;
		m_last_fps_update_time = now;
	}

	m_text_y = 10;

	print_line("FPS: " + std::to_string(m_fps));
}

void debug_info_system::set_font(sf::Font& font)
{
	m_font = &font;
	m_text.setFont(font);
}

void debug_info_system::print_line(std::string const& string)
{
	m_text.setString(string);
	m_text.setPosition(10, m_text_y);
	m_render_target.draw(m_text);

	m_text_y += m_font->getLineSpacing(24);
}
