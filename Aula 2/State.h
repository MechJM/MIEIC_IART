#pragma once

#include <vector>
#include <string>

class State
{
    private:
        bool useless;
    public:
        virtual ~State() {};
        virtual std::vector<State*> getChildrenStates() {return {};};
        virtual bool operator==(const State &rhs) const {return rhs.useless;};
};

class NPuzzleState : public virtual State
{
    private:
        std::vector<std::vector<unsigned>> matrix;
        std::pair<unsigned, unsigned> emptySpaceCoords;
        bool checkPreconditions(std::string direction);
        NPuzzleState* applyOperator(std::string direction);
    public:
        NPuzzleState(std::vector<std::vector<unsigned>> &matrix);
        virtual bool operator==(const NPuzzleState &rhs) const;
        virtual std::vector<State*> getChildrenStates();
        std::vector<std::vector<unsigned>>& getMatrix();
        std::pair<unsigned,unsigned> getEmptySpaceCoords();
};