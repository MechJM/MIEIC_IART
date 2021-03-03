#pragma once

#include "State.h"
#include <string>

class Operator
{
    public:
        virtual ~Operator() {};
        virtual bool checkPreconditions();
        virtual State* applyOperator();
};

class NPuzzleOperator: public virtual Operator
{
    private:
        State* state;
        std::string direction;
    public:
        NPuzzleOperator(State* state, std::string direction);
        virtual bool checkPreconditions();
        virtual State* applyOperator();


};