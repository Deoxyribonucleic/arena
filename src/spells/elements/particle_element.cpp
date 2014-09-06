#include "particle_element.hpp"

#include "assets/asset_loader.hpp"
#include "components/collision_component.hpp"
#include "components/controller_component.hpp"
#include "components/movement_component.hpp"
#include "components/position_component.hpp"
#include "components/render_component.hpp"
#include "components/player_component.hpp"
#include "components/lifetime_component.hpp"
#include "components/orientation_component.hpp"
#include "components/spell_component.hpp"
#include "components/particle_emitter_component.hpp"
#include "components/projectile_component.hpp"


using namespace game;

particle_element::particle_element(
	dawn::time::duration lifetime,
	const glm::vec3& color_start,
	const glm::vec3& color_end,
	const glm::vec3& target_color,
	float size_start, float size_end,
	float frequency,
	float cone_size,
	const glm::vec2& direction,
	float speed,
	float friction,
	dawn::time::duration particle_lifetime,
	dawn::entity::ptr follow)
: spell_element(0),
	m_lifetime(lifetime),
	m_emitter(
		color_start, color_end,
		target_color,
		size_start, size_end,
		frequency,
		cone_size,
		direction,
		speed,
		friction,
		particle_lifetime,
		follow
		)
{

}

void particle_element::spawn(dawn::entity_list& entities, dawn::entity::ptr origin)
{
	assert(origin->has_component<position_component>());

	dawn::entity::ptr entity = std::make_shared<dawn::entity>();

	entity->add_component<position_component>(origin->get_component<position_component>().position);
	entity->add_component<lifetime_component>(m_lifetime);
	entity->add_component<particle_emitter_component>(m_emitter);

	entities.add_entity(entity);
}
