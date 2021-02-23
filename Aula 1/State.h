#include <vector>

class State
{
    private:
    int c1,c2,max_c1,max_c2;

    public:
    State(int c1, int c2, int max_c1, int max_c2);
    std::vector<State*> getChildrenStates();
};