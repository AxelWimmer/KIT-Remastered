#include "Matrix_Agent.h"

std::vector<bool> matrix_agent::process_token(const std::vector<bool>& state_before, token t)
{
    std::vector<bool> new_state(state_count);
    for (const auto& state : state_before)
    {

        for (int i = 0; i < state_count; i++)
        {
            if(transition_condition(state, i).contains(t))
                new_state[i] = true;
        }
    }
    return new_state;
}
