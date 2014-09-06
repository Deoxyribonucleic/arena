#include "player_factory.hpp"

#include "assets/asset_loader.hpp"
#include "components/bounding_box_component.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"
#include "components/health_component.hpp"
#include "components/orientation_component.hpp"


using namespace game;

player_factory::player_factory(asset_loader& loader)
: m_loader(loader)
{
}

dawn::entity::ptr player_factory::create(int number, int controller_id, const glm::vec2& position)
{
	dawn::entity::ptr entity(new dawn::entity);

	sf::Color player_color;
	switch((number - 1) % 4 + 1)
	{
		case 1:
			player_color = sf::Color::Blue;
			break;
		case 2:
			player_color = sf::Color::Red;
			break;
		case 3:
			player_color = sf::Color::Green;
			break;
		case 4:
			player_color = sf::Color::White;
			break;
	}

	entity->add_component<player_component>(number, m_loader, player_color);
	entity->add_component<controller_component>(controller_id);
	entity->add_component<health_component>(40);
	entity->add_component<orientation_component>(glm::vec2(1, 0));
	entity->add_component<position_component>(position);
	entity->add_component<movement_component>(glm::vec2(0, 0), 200.0, 1800.0, 800.0);
	entity->add_component<bounding_box_component>(64, 64);
	entity->add_component<render_component>(m_loader.get_sprite(sprites::player), player_color);

	return entity;
}
