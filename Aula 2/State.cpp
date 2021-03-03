#include "State.h"

NPuzzleState::NPuzzleState(std::vector<std::vector<unsigned>> &matrix)
{   
    this->matrix = matrix;

}

bool NPuzzleState::operator==(const State &rhs) const
{

}

std::vector<State*> NPuzzleState::getChildrenStates()
{

}