#pragma once

#include <vector>
#include "Operator.h"

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
        std::vector<Operator*> operators;
        void buildOperators();
    public:
        NPuzzleState(std::vector<std::vector<unsigned>> &matrix);
        virtual bool operator==(const NPuzzleState &rhs) const;
        virtual std::vector<State*> getChildrenStates();
        std::vector<std::vector<unsigned>>& getMatrix();
        std::pair<unsigned,unsigned> getEmptySpaceCoords();
};