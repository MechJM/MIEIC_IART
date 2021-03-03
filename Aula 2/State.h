#pragma once

#include <vector>

class State
{
    public:
        virtual ~State() {};
        virtual std::vector<State*> getChildrenStates();
        virtual bool operator==(const State &rhs) const;
};

class NPuzzleState : public virtual State
{
    private:
        std::vector<std::vector<unsigned>> matrix;
        std::pair<unsigned, unsigned> emptySpaceCoords;
    public:
        NPuzzleState(std::vector<std::vector<unsigned>> &matrix);
        virtual bool operator==(const State &rhs) const;
        virtual std::vector<State*> getChildrenStates();
};