#pragma once

#include "components/position_component.hpp"
#include "particle.hpp"
#include "util/math.hpp"

#include <dawn/ecs/entity.hpp>
#include <dawn/ecs/component.hpp>

#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <cmath>
#include <memory>


namespace game
{
	class particle_emitter
	{
	public:
		particle_emitter(
			const glm::vec3& color_start,
			const glm::vec3& color_end,
			const glm::vec3& target_color,
			float size_start,
			float size_end,
			float frequency,
			float cone_size,
			const glm::vec2& direction,
			float speed,
			float friction,
			dawn::time::duration lifetime,
			dawn::entity::ptr follow = nullptr
		)
		:
		m_color_start(color_start),
		m_color_end(color_end),
		m_target_color(target_color),
		m_size_start(size_start),
		m_size_end(size_end),
		m_interval(1.0f / frequency),
		m_cone_size(cone_size),
		m_direction(direction),
		m_speed(speed),
		m_friction(friction),
		m_time_since_last(0.f),
		m_lifetime(lifetime),
		m_follow(follow)
		{
		}

		void update(float delta_time, const glm::vec2& where, particle_list& particles)
		{
			auto now = dawn::time::clock::now();

			// spawn new particles
			m_time_since_last += delta_time;

			while(m_time_since_last - m_interval >= 0.0f)
			{
				m_time_since_last -= m_interval;

				float particle_angle = rand() % 360;
				float particle_rotation = rand() % 360;

				auto follow = m_follow.lock();

				particles.push_back(particle{
					get_color(),
					get_size(),
					particle_rotation,
					m_friction,
					(follow ? glm::vec2{0, 0} : where),
					glm::vec2{ glm::cos(glm::radians(particle_angle)), glm::sin(glm::radians(particle_angle)) } * m_speed,
					m_lifetime,
					now + m_lifetime,
					(follow ? follow : nullptr)
				});
			}
		}

	protected:
		virtual glm::vec3 get_color() const
		{
			//return sf::Color(0, 0, 80);//sf::Color::Blue;
			glm::vec3 step = (m_color_end - m_color_start) / 4.0f;
			float color_number = rand() % 5;

		 	return m_color_start + step * color_number;
			//return sf::Color(selected_color.r, selected_color.g, selected_color.b);
		}

		virtual float get_size() const
		{
			return (rand() % (int)((m_size_end - m_size_start) * 10.0f)) / 10.0f + m_size_start;
		}

	private:
		glm::vec3 m_color_start, m_color_end;
		glm::vec3 m_target_color;
		float m_size_start, m_size_end;
		float m_interval;
		float m_cone_size;
		glm::vec2 m_direction;
		float m_speed;
		float m_friction;
		dawn::time::duration m_lifetime;

		float m_time_since_last;

		std::weak_ptr<dawn::entity> m_follow;
	};
}
