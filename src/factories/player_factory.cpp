#include "player_factory.hpp"

#include "assets/asset_loader.hpp"
#include "components/controller_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"


using namespace game;

player_factory::player_factory(asset_loader& loader)
: m_loader(loader)
{
}

dawn::entity::ptr player_factory::create(const std::string& name)
{
	dawn::entity::ptr entity(new dawn::entity);

	entity->add_component<controller_component>();
	entity->add_component<position_component>(100, 100);
	entity->add_component<render_component>(m_loader.get_sprite(sprites::player));

	return entity;
}
