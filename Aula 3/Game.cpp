#include "Game.h"

Game::Game() 
{
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            matrix[i][j] = 0;
        }   
    }
}

Game::Game(int matrix[6][7])
{
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

int Game::central(int player)
{
    int total = 0;

    for (size_t i = 0; i < 6; i++)
    {
        if (matrix[i][3] == player) total++;
        if (matrix[i][4] == player) total += 2;
        if (matrix[i][5] == player) total++;
    }
    
    return total;
}

int Game::nlines3(int player)
{
    auto lines = getAllLines();

    int result = 0;
    int lineCount = 0;
    bool foundEmptySpot = false;
    int startingIndex = -1;

    for (auto line : lines)
    {
        if (line.size() < 4) continue;
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == player)
            {
                if (startingIndex == -1 && lineCount == 0) startingIndex = i;
                lineCount++;
            }
            else
            {
                startingIndex = -1;
                lineCount = 0;
            }

            if (lineCount == 3)
            {
                if ((startingIndex > 0 && line[startingIndex - 1] == 0) || (i < (line.size() - 1) && line[i + 1] == 0))
                {
                    result++;
                }
            }
        }
        startingIndex = -1;
        lineCount = 0;
    }
    return result;
}

int Game::nlines4(int player)
{
    auto lines = getAllLines();
    int result = 0;

    int lineCount = 0;
    for (auto line : lines)
    {
        for (int elem : line)
        {
            if (elem == player) lineCount++;
        }
        if (lineCount == 4) result++; 
        lineCount = 0;
    }
    return result;
}

vector<vector<int>> Game::getAllLines()
{
    vector<vector<int>> lines;

    for (auto line : getRows()) lines.push_back(line);
    for (auto line : getCols()) lines.push_back(line);
    for (auto line : getDiags()) lines.push_back(line);

    return lines;
}

vector<vector<int>> Game::getRows()
{
    vector<vector<int>> rows;

    for (size_t i = 0; i < 6; i++)
    {
        vector<int> currentRow;
        for (size_t j = 0; j < 7; j++)
        {
            currentRow.push_back(matrix[i][j]);
        }
        rows.push_back(currentRow);
    }
    
    return rows;
}

vector<vector<int>> Game::getCols()
{
    vector<vector<int>> cols;

    for (size_t i = 0; i < 7; i++)
    {
        vector<int> currentCol;
        for (size_t j = 0; j < 6; j++)
        {
            currentCol.push_back(matrix[j][i]);
        }
        cols.push_back(currentCol);
    }
    
    return cols;
}

vector<vector<int>> Game::getDiags()
{
    vector<vector<int>> diags;

    int i = 5, j = 0;

    while (i >= 0) diags.push_back(getOneDiag(i--, j, true));

    i = 0, j = 0;
    
    while (j < 7) diags.push_back(getOneDiag(i, ++j, true));

    i = 5, j = 6;

    while (i >= 0) diags.push_back(getOneDiag(i--, j, false));

    i = 0, j = 6;

    while (j >= 0) diags.push_back(getOneDiag(i, --j, false));

    return diags;
}

vector<int> Game::getOneDiag(int i, int j, bool LTR)
{
    vector<int> diag;

    if (LTR)
    {
        while (i < 6 && j < 7)
        {
            diag.push_back(matrix[i][j]);
            i++;
            j++;
        }
    }
    else
    {
        while (i < 6 && j >= 0)
        {
            diag.push_back(matrix[i][j]);
            i++;
            j--;
        }
    }

    return diag;
}

Game* Game::applyOperator(int col, int player)
{
    
    int newMatrix[6][7];
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
        {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    for (size_t i = 5; i >= 0; i--)
    {
        if (matrix[i][col] == 0)
        {
            newMatrix[i][col] = player; 
            break;
        } 
    }
    return new Game(newMatrix);

}

vector<Game*> Game::getChildren(int player)
{
    vector<Game*> children;
    for (size_t i = 0; i < 7; i++)
    {
        if (matrix[0][i] == 0) children.push_back(applyOperator(i, player));
    }
    return children;
}