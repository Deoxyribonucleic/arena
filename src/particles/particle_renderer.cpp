#include "particle_renderer.hpp"

#include "components/position_component.hpp"


using namespace game;

particle_renderer::particle_renderer()
: m_shape(sf::Vector2f(1, 1))
{

}

void particle_renderer::render(sf::RenderWindow& render_target, const particle_list& particles)
{
	auto now = dawn::time::clock::now();

	for(auto& particle: particles)
	{
		m_shape.setScale(particle.size, particle.size);
		m_shape.setRotation(particle.rotation);

		//glm::vec3 effective_color = particle.color + (1.0f - (float)(particle.expire_at - now).count() / (float)particle.lifetime.count()) * (particle.target_color - particle.color);
		m_shape.setFillColor(sf::Color(particle.color.r, particle.color.g, particle.color.b, std::abs(((float)(particle.expire_at - now).count() / (float)particle.lifetime.count()) * 255.0f)));

		dawn::entity::ptr origin;
		if(origin = particle.origin.lock())
		{
			auto position = origin->get_component<position_component>().position;
			m_shape.setPosition(particle.position.x + position.x, particle.position.y + position.y);
		}
		else
		{
			m_shape.setPosition(particle.position.x, particle.position.y);
		}

		render_target.draw(m_shape);
	}
}
