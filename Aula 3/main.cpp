#include "Game.h"


int minimax(Game* node, int depth, bool maximizingPlayer, int currentPlayer)
{
    int nextPlayer = ((currentPlayer == 1) ? 2 : 1);

    vector<Game*> nodeChildren = node->getChildren(maximizingPlayer);

    if (depth == 0 || nodeChildren.size() == 0) return node->central(maximizingPlayer);

    if (maximizingPlayer)
}


int main(int argc, char* argv[])
{




    return 0;
}