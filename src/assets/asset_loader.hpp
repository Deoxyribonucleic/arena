#pragma once

#include "fonts.hpp"
#include "sprites.hpp"
#include "textures.hpp"

#include <SFML/Graphics.hpp>

#include <map>
#include <mutex>


namespace game
{
	class asset_loader
	{
	public:
		asset_loader(const std::string& root);

		void add_font(fonts::font name, const std::string& file);
		void add_texture(textures::texture name, const std::string& file);
		void add_sprite(sprites::sprite name, textures::texture texture);

		void load();
		bool is_loaded();

		sf::Font& get_font(fonts::font name);
		sf::Texture& get_texture(textures::texture name);
		sf::Sprite& get_sprite(sprites::sprite name);

		bool font_exists(fonts::font name);
		bool texture_exists(textures::texture name);
		bool sprite_exists(sprites::sprite name);

	private:
		std::string m_root;
		std::mutex m_lock;
		volatile bool m_loaded;

		std::vector<std::pair<fonts::font, std::string>> m_fonts_to_load;
		std::vector<std::pair<textures::texture, std::string>> m_textures_to_load;
		std::vector<std::pair<sprites::sprite, textures::texture>> m_sprites_to_load;

		std::map<fonts::font, sf::Font> m_fonts;
		std::map<textures::texture, sf::Texture> m_textures;
		std::map<sprites::sprite, sf::Sprite> m_sprites;
	};
}
