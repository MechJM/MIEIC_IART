#pragma once

#include "State.h"
#include <vector>
#include <iostream>

class Node
{
    private:
    State* state;
    std::vector<Node*> children;

    public:
    bool visited;
    Node(State* state);
    State* getState();
    std::vector<Node*> getChildren();
    bool operator==(const Node &right) const;
};