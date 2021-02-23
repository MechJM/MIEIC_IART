#include "State.h"
#include <vector>

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
    bool operator==(Node right);
};