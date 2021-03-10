#include "Game.h"

Game::Game() {}

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

    int i = 0, j = 0;
    
    while (j < 7) diags.push_back(getOneDiag(i, ++j, true));

    int i = 5, j = 6;

    while (i >= 0) diags.push_back(getOneDiag(i--, j, false));

    int i = 0, j = 6;

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