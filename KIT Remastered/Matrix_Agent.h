#pragma once
#include <vector>

using token = std::size_t;
using state_id = std::size_t;

class token_set
{
public:
	bool contains(token t)const;

	void grow();
	void shrink();
};
class matrix_agent
{
	using state_id = std::size_t;
	std::vector<token_set> transitions;

	std::vector<bool> binary_description(token t);

	std::size_t state_count;
	token_set& transition_condition(state_id from, state_id to);

	std::vector<bool> process_token(const std::vector<bool>& state_before, token t);
};

using sup_state = std::vector<bool>;
class successor_table
{
	int state_count;
	std::vector<bool> transitions;

	bool has_transition(state_id from, state_id to) const;
	sup_state apply(const sup_state& before);
};