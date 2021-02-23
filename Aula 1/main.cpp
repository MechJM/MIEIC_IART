#include "Tree.h"
#include <iostream>

int main()
{
    State initial(0,0,4,3);
    Node root(&initial);

    Tree tree(&root);
    Node target(new State(2,0,4,3));
    int cost = 0;
    int bfsCost = tree.bfs(&target);
    int dfsCost = tree.dfs(&target, tree.getRoot(), 10, 0, cost);
    int iterativeCost = tree.iterativeDeepening(&target, 10);
    
    std::cout << "BFS: " << bfsCost << std::endl;
    std::cout << "DFS: " << dfsCost << std::endl;
    std::cout << "Iterative Deepening: " << iterativeCost << std::endl;

    return 0;
}