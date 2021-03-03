#include "State.h"

NPuzzleState::NPuzzleState(std::vector<std::vector<unsigned>> &matrix)
{   
    this->matrix = matrix;

    bool foundHole = false;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(0).size(); j++)
        {
            if (matrix.at(i).at(j) == 0)
            {
                emptySpaceCoords = std::pair<unsigned, unsigned>(j,i);
                foundHole = true;
                break;
            } 
        } 
        if (foundHole) break;
    }
    buildOperators();
}

bool NPuzzleState::operator==(const NPuzzleState &rhs) const
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(0).size(); j++)
        {
            if (matrix.at(i).at(j) != rhs.matrix.at(i).at(j)) return false;
        }
    }
    return true;
}

std::vector<State*> NPuzzleState::getChildrenStates()
{
    std::vector<State*> children;

    for (auto i : operators) children.push_back(i->applyOperator());

    return children;
}

std::vector<std::vector<unsigned>>& NPuzzleState::getMatrix()
{
    return matrix;
}

void NPuzzleState::buildOperators()
{
    NPuzzleOperator* moveHoleUp = new NPuzzleOperator(this, "up"); 
    NPuzzleOperator* moveHoleRight = new NPuzzleOperator(this, "right"); 
    NPuzzleOperator* moveHoleDown = new NPuzzleOperator(this, "down"); 
    NPuzzleOperator* moveHoleLeft = new NPuzzleOperator(this, "left");

    if (moveHoleUp->checkPreconditions()) operators.push_back(moveHoleUp);
    if (moveHoleRight->checkPreconditions()) operators.push_back(moveHoleRight);
    if (moveHoleDown->checkPreconditions()) operators.push_back(moveHoleDown);
    if (moveHoleLeft->checkPreconditions()) operators.push_back(moveHoleLeft); 
}

std::pair<unsigned,unsigned> NPuzzleState::getEmptySpaceCoords()
{
    return emptySpaceCoords;
}