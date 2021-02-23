#include "State.h"

class Node
{
    private:
    State* state;

    public: 
    Node(State* state);
    State* getState();
};