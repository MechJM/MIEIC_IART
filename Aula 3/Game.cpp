#include "Game.h"

Game::Game() {}

int Game::nlines4(int player)
{
    return searchCols(player, 4, false) + searchDiag(player, 4, false) + searchRows(player, 4, false);
}

int Game::searchRows(int player, int count, bool consecutive)
{
    int rowCount = 0, total = 0;

    if (!consecutive)
    {
        for (size_t i = 0; i < 6; i++)
        {
            for (size_t j = 0; j < 7; j++)
            {
                if (matrix[i][j] == player) rowCount++;            
            }
            if (rowCount == count) total++; 
            rowCount = 0;
        }
    }
    else
    {
        for (size_t i = 0; i < 6; i++)
        {
            for (size_t j = 0; j < 7; j++)
            {
                if (matrix[i][j] == player) rowCount++;
                else rowCount = 0;
                if (rowCount >= count) total++;
            }
            rowCount = 0;
        }
        
    }
    
    return total;
}

int Game::searchCols(int player, int count, bool consecutive)
{

}

int Game::searchDiag(int player, int count, bool consecutive)
{

}