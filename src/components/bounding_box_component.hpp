#pragma once

#include <dawn/ecs/component.hpp>
#include <dawn/time.hpp>

#include <glm/glm.hpp>


namespace game
{
	class bounding_box_component : public dawn::component
	{
	public:
		bounding_box_component(int width, int height)
		: width(width), height(height)
		{
		}

		inline bool is_within(const glm::vec2& position, const glm::vec2& point) const
		{
			auto rect = get_absolute(position);

			return (point.x > rect.x && point.x < rect.z &&
			        point.y > rect.y && point.y < rect.w);
		}

		inline glm::vec4 get_absolute(const glm::vec2& position) const
		{
			return glm::vec4(position.x - width / 2, position.y - height / 2, position.x + width / 2, position.y + height / 2);
		}

		int width, height;
	};
}
