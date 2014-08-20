#include "state_stack.hpp"

#include "states/test_state.hpp"

#include <cassert>
#include <iostream>


using namespace game;

state_stack::state_stack()
{

}

state_stack::~state_stack()
{

}

void state_stack::update()
{
	do_operations();

	assert(m_states.size() > 0);

	for(auto& state: get_state_group(false))
	{
		if(state.get() == get_state_group(false).back().get())
			state->update(true);
		else
			state->update(false);
	}
}

void state_stack::render()
{
	assert(m_states.size() > 0);

	for(auto& state: get_state_group(false))
	{
		if(state.get() == get_state_group(false).back().get())
			state->render(true);
		else
			state->render(false);
	}
}

void state_stack::force_stack_update()
{
	do_operations();
}

void state_stack::push_state(std::unique_ptr<state> state, bool new_group)
{
	assert(state);
	m_operations.push_back(state_stack::stack_operation{state_stack::stack_operation_type::push, std::move(state), new_group});
}

void state_stack::pop_state()
{
	m_operations.push_back(state_stack::stack_operation{state_stack::stack_operation_type::pop});
}

void state_stack::do_operations()
{
	for(auto& operation: m_operations)
	{
		switch(operation.type)
		{
			case stack_operation_type::pop:
				do_pop_state();
				break;
			case stack_operation_type::push:
				do_push_state(std::move(operation.new_state), operation.new_group);
				break;
		}
	}

	m_operations.clear();
}

void state_stack::do_pop_state()
{
	assert(m_states.size() > 0);
	auto& group = get_state_group(false);

	group.pop_back();
	if(group.size() == 0)
		m_states.pop_back();
}

void state_stack::do_push_state(std::unique_ptr<state> state, bool new_group)
{
	assert(state);
	auto& group = get_state_group(new_group);
	group.push_back(std::move(state));
}

state_stack::state_group& state_stack::get_state_group(bool new_group)
{
	if(new_group || m_states.size() == 0)
		create_state_group();

	return m_states.back();
}

void state_stack::create_state_group()
{
	m_states.push_back(state_stack::state_group());
}
