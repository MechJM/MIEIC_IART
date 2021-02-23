#include "State.h"

State::State(int c1, int c2, int max_c1, int max_c2)
{
    this->c1 = c1;
    this->c2 = c2;
    this->max_c1 = max_c1;
    this->max_c2 = max_c2;
}

std::vector<State*> State::getChildrenStates()
{
    std::vector<State*> result;

    if (c1 > 0) result.push_back(new State(0, c2, max_c1, max_c2));
    if (c2 > 0) result.push_back(new State(c1, 0, max_c1, max_c2));
    if (c1 < max_c1) result.push_back(new State(max_c1, c2, max_c1, max_c2));
    if (c2 < max_c2) result.push_back(new State(c1, max_c2, max_c1, max_c2));

    int c1_after_moving_from_c1_to_c2, c2_after_moving_from_c1_to_c2;
    int c1_after_moving_from_c2_to_c1, c2_after_moving_from_c2_to_c1;

    int diff_to_max_c1 = max_c1 - c1;
    int diff_to_max_c2 = max_c2 - c2;

    if (diff_to_max_c2 < c1)
    {
        c1_after_moving_from_c1_to_c2 = c1 - diff_to_max_c2;
        c2_after_moving_from_c1_to_c2 = max_c2;
    }
    else
    {
        c1_after_moving_from_c1_to_c2 = 0;
        c2_after_moving_from_c1_to_c2 = c2 + c1;
    }

    if (diff_to_max_c1 < c2)
    {
        c2_after_moving_from_c2_to_c1 = c2 - diff_to_max_c1;
        c1_after_moving_from_c2_to_c1 = max_c1;
    }
    else
    {
        c2_after_moving_from_c2_to_c1 = 0;
        c1_after_moving_from_c2_to_c1 = c2 + c1;
    }


    if (c1 > 0 && diff_to_max_c2 > 0) result.push_back(new State(c1_after_moving_from_c1_to_c2, c2_after_moving_from_c1_to_c2, max_c1, max_c2));
    if (c2 > 0 && diff_to_max_c1 > 0) result.push_back(new State(c1_after_moving_from_c2_to_c1, c2_after_moving_from_c2_to_c1, max_c1, max_c2));

    return result;
}