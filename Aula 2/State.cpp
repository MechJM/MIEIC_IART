#include "State.h"

NPuzzleState::NPuzzleState(std::vector<std::vector<unsigned>> &matrix)
{   
    this->matrix = matrix;

    bool foundHole = false;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.at(0).size(); j++)
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
}

bool NPuzzleState::operator==(const NPuzzleState &rhs) const
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.at(0).size(); j++)
        {
            if (matrix.at(i).at(j) != rhs.matrix.at(i).at(j)) return false;
        }
    }
    return true;
}

std::vector<State*> NPuzzleState::getChildrenStates()
{
    std::vector<State*> children;

    if (checkPreconditions("up")) children.push_back(applyOperator("up"));
    if (checkPreconditions("left")) children.push_back(applyOperator("left"));
    if (checkPreconditions("down")) children.push_back(applyOperator("down"));
    if (checkPreconditions("right")) children.push_back(applyOperator("right"));

    return children;
}

std::vector<std::vector<unsigned>>& NPuzzleState::getMatrix()
{
    return matrix;
}

std::pair<unsigned,unsigned> NPuzzleState::getEmptySpaceCoords()
{
    return emptySpaceCoords;
}

bool NPuzzleState::checkPreconditions(std::string direction)
{
    auto emptySpaceCoords = this->getEmptySpaceCoords();
    auto matrix = this->getMatrix();
    unsigned numRows = matrix.size();
    unsigned numCols = matrix.at(0).size();

    if (direction == "up" && emptySpaceCoords.second == 0) return false;
    if (direction == "down" && emptySpaceCoords.second == (numRows - 1)) return false;
    if (direction == "right" && emptySpaceCoords.first == (numCols - 1)) return false;
    if (direction == "left" && emptySpaceCoords.first == 0) return false;

    return true;
}

NPuzzleState* NPuzzleState::applyOperator(std::string direction)
{
    auto matrix = this->getMatrix();
    std::vector<std::vector<unsigned>>* matrixCopy = new std::vector<std::vector<unsigned>>;

    for (size_t i = 0; i < matrix.at(0).size(); i++)
    {
        std::vector<unsigned> line;
        for (size_t j = 0; j < matrix.size(); j++)
        {
            line.push_back(matrix.at(j).at(i));
        }
        matrixCopy->push_back(line);
    }
    
    auto emptySpaceCoords = this->getEmptySpaceCoords();
    unsigned emptyX = emptySpaceCoords.first;
    unsigned emptyY = emptySpaceCoords.second;

    std::pair<unsigned,unsigned> newHoleCoords;

    if (direction == "up") newHoleCoords = std::pair<unsigned,unsigned>(emptyX, emptyY - 1);
    if (direction == "down") newHoleCoords = std::pair<unsigned,unsigned>(emptyX, emptyY + 1);
    if (direction == "left") newHoleCoords = std::pair<unsigned,unsigned>(emptyX - 1, emptyY);
    if (direction == "right") newHoleCoords = std::pair<unsigned,unsigned>(emptyX + 1, emptyY);

    unsigned numberChanged = matrixCopy->at(newHoleCoords.first).at(newHoleCoords.second);
    matrixCopy->at(newHoleCoords.first).at(newHoleCoords.second) = 0;
    matrixCopy->at(emptyX).at(emptyY) = numberChanged;

    return new NPuzzleState(*matrixCopy);
}