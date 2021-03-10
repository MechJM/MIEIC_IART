#pragma once
#include <vector>

using namespace std;

class Game
{
    private:
        int matrix[6][7];
        vector<vector<int>> getRows();
        vector<vector<int>> getCols();
        vector<vector<int>> getDiags();
        vector<int> getOneDiag(int i, int j, bool LTR);
        vector<vector<int>> getAllLines();
        Game* applyOperator(int col, int player);
    public:
        Game();
        Game(int matrix[6][7]);
        int nlines4(int player); //not consecutive
        int nlines3(int player);
        int central(int player);
        vector<Game*> getChildren(int player);
};