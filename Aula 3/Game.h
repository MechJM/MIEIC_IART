#pragma once
#include <vector>

using namespace std;

class Game
{
    private:
        int matrix[6][7];
        int searchRows(int player, int count, bool consecutive);
        int searchCols(int player, int count, bool consecutive);
        int searchDiag(int player, int count, bool consecutive);
    public:
        Game();
        int nlines4(int player); //not consecutive
};