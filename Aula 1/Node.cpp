#include "Node.h"

Node::Node(State* state)
{
    visited = false;
    this->state = state;
}

State* Node::getState()
{
    return state;
}

std::vector<Node*> Node::getChildren()
{
    std::vector<State*> stateChildren = state->getChildrenStates();
    for (auto i : stateChildren)
    {
        children.push_back(new Node(i));
    }
    return children;
}

bool Node::operator==(Node right)
{
    return (*this->state) == (*right.state);
}

