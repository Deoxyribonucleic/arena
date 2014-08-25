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

#include <glm/glm.hpp>


using namespace game;

player_factory::player_factory(asset_loader& loader)
: m_loader(loader)
{
}

dawn::entity::ptr player_factory::create(int number, int controller_id)
{
	dawn::entity::ptr entity(new dawn::entity);

	entity->add_component<player_component>(number);
	entity->add_component<controller_component>(controller_id);
	entity->add_component<health_component>(40);
	entity->add_component<orientation_component>(glm::vec2(1, 0));
	entity->add_component<position_component>(glm::vec2(100, 100));
	entity->add_component<movement_component>(glm::vec2(0, 0), 200.0, 1800.0, 800.0);
	entity->add_component<bounding_box_component>(32, 32);
	entity->add_component<render_component>(m_loader.get_sprite(sprites::player), false);

	return entity;
}
