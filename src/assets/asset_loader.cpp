#include "asset_loader.hpp"

#include <cassert>
#include <iostream>


using namespace game;

asset_loader::asset_loader(const std::string& root)
:
m_root(root),
m_loaded(true)
{

}

void asset_loader::add_font(fonts::font name, const std::string& file)
{
	std::lock_guard<std::mutex> guard(m_lock);
	m_fonts_to_load.push_back(std::pair<fonts::font, std::string>(name, file));
	m_loaded = false;
}

void asset_loader::add_texture(textures::texture name, const std::string& file)
{
	std::lock_guard<std::mutex> guard(m_lock);
	m_textures_to_load.push_back(std::pair<textures::texture, std::string>(name, file));
	m_loaded = false;
}

void asset_loader::add_sprite(sprites::sprite name, textures::texture texture)
{
	std::lock_guard<std::mutex> guard(m_lock);
	m_sprites_to_load.push_back(std::pair<sprites::sprite, textures::texture>(name, texture));
	m_loaded = false;
}

void asset_loader::load()
{
	std::lock_guard<std::mutex> guard(m_lock);

	// fonts
	for(auto& font: m_fonts_to_load)
	{
		if(!font_exists(font.first))
		{
			m_fonts[font.first].loadFromFile(m_root + "/" + font.second);
		}
	}
	m_fonts_to_load.clear();

	// textures
	for(auto& texture: m_textures_to_load)
	{
		if(!texture_exists(texture.first))
		{
			m_textures[texture.first].loadFromFile(m_root + "/" + texture.second);
		}
	}
	m_textures_to_load.clear();

	// sprites
	for(auto& sprite: m_sprites_to_load)
	{
		if(!sprite_exists(sprite.first) && texture_exists(sprite.second))
		{
			m_sprites[sprite.first] = sf::Sprite(get_texture(sprite.second));
		}
	}
	m_sprites_to_load.clear();

	m_loaded = true;
}

bool asset_loader::is_loaded()
{
	return m_loaded;
}

sf::Font& asset_loader::get_font(fonts::font name)
{
	return m_fonts[name];
}

sf::Texture& asset_loader::get_texture(textures::texture name)
{
	return m_textures[name];
}

sf::Sprite& asset_loader::get_sprite(sprites::sprite name)
{
	return m_sprites[name];
}

bool asset_loader::font_exists(fonts::font name)
{
	return m_fonts.find(name) != m_fonts.end();
}

bool asset_loader::texture_exists(textures::texture name)
{
	return m_textures.find(name) != m_textures.end();
}

bool asset_loader::sprite_exists(sprites::sprite name)
{
	return m_sprites.find(name) != m_sprites.end();
}
