#pragma once

#include "state.hpp"

#include <vector>
#include <memory>


namespace game
{
	class state;
	class state_stack final
	{
	public:
		state_stack();
		~state_stack();

		void push_state(std::unique_ptr<state> state, bool new_group = false);
		void pop_state();

		void update();
		void render();

		void force_stack_update();

	private:
		enum stack_operation_type
		{
			push, pop
		};

		struct stack_operation
		{
			stack_operation_type type;

			// only relevant if type == push
			std::unique_ptr<state> new_state;
			bool new_group;
		};

		typedef std::vector<std::unique_ptr<state>> state_group;

		state_group& get_state_group(bool new_group);
		void create_state_group();

		void do_operations();
		void do_pop_state();
		void do_push_state(std::unique_ptr<state> state, bool new_group);

		std::vector<state_group> m_states;
		std::vector<stack_operation> m_operations;
	};
}
