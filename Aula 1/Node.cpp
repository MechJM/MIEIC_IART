#include "Node.h"

Node::Node(State* state)
{
    visited = false;
    this->state = state;

    std::vector<State*> stateChildren = state->getChildrenStates();
    for (auto i : stateChildren)
    {
        children.push_back(new Node(i));
    }
}

State* Node::getState()
{
    return state;
}

std::vector<Node*> Node::getChildren()
{
    return children;
}

bool Node::operator==(Node right)
{
    return (*this->state) == (*right.state);
}

