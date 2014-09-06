#include "player_factory.hpp"

#include "assets/asset_loader.hpp"
#include "components/bounding_box_component.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"
#include "components/particle_emitter_component.hpp"
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
	/*entity->add_component<particle_emitter_component>(
		glm::vec3{0.f, 0.f, 0.f},
		glm::vec3{255.f, 255.f, 255.f},
		glm::vec3{255.f, 255.f, 255.f},
		1.f, 2.f,
		200.f,
		360.f,
		glm::vec2{1.f, 0.f},
		100.0f,
		70.0f,
		std::chrono::milliseconds(4000),
		entity);*/
	//entity->add_component<particle_emitter_component>();

	return entity;
}
