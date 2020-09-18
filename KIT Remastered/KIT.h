#pragma once
#include <vector>


class clause
{
	using var_id = std::size_t;
	using sign = bool;
	std::vector <std::pair<var_id, sign>> _literals;
	bool evaluate(const std::vector<bool>& _inputs);
public:
	void add_literal(std::size_t var_id, bool negated);

	void drop_at_position(std::size_t position);
	void drop_literal(std::size_t var_id);
	void drop_positive_literal(std::size_t var_id);
	void drop_negative_literal(std::size_t var_id);
};

class KIT
{
	using bool_func = std::vector<clause>;
	std::vector<bool> _inputs;
	
	std::vector<bool> _outputs;
	std::vector<bool_func> _funcs_for_outputs;

public:
	void set_input(std::size_t index, bool value);
	void compute_output();
	bool get_input(std::size_t index);
};

class Network
{
	struct connection
	{
		std::size_t _output_port;
		KIT* receivee;
		std::size_t _input_port;
	};

	using connections = std::vector<connection>;
	connections _input_layer;
	std::vector<std::pair<KIT*,connections>> _hidden_layer;
	connections _output_layer;
};



