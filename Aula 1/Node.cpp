#include "Node.h"

Node::Node(State* state)
{
    this->state = state;
}

State* Node::getState()
{
    return state;
}