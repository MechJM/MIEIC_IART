#include "Operator.h"

NPuzzleOperator::NPuzzleOperator(NPuzzleState* state, std::string direction)
{
    this->state = state;
    this->direction = direction;
}

bool NPuzzleOperator::checkPreconditions()
{
    auto emptySpaceCoords = state->getEmptySpaceCoords();
    auto matrix = state->getMatrix();
    unsigned numRows = matrix.size();
    unsigned numCols = matrix.at(0).size();

    if (direction == "up" && emptySpaceCoords.second == 0) return false;
    if (direction == "down" && emptySpaceCoords.second == (numRows - 1)) return false;
    if (direction == "right" && emptySpaceCoords.first == (numCols - 1)) return false;
    if (direction == "left" && emptySpaceCoords.first == 0) return false;

    return true;
}

NPuzzleState* NPuzzleOperator::applyOperator()
{
    auto matrix = state->getMatrix();
    std::vector<std::vector<unsigned>>* matrixCopy = new std::vector<std::vector<unsigned>>;

    for (int i = 0; i < matrix.at(0).size(); i++)
    {
        std::vector<unsigned> line;
        for (int j = 0; j < matrix.size(); j++)
        {
            line.push_back(matrix.at(j).at(i));
        }
        matrixCopy->push_back(line);
    }
    
    auto emptySpaceCoords = state->getEmptySpaceCoords();
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