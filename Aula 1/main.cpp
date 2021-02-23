#include "Tree.h"
#include <iostream>

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: bucket <depth limit>\n";
        exit(1);
    } 
    int depth_limit = atoi(argv[1]);

    State initial(0,0,4,3);
    Node root(&initial);

    Tree tree(&root);
    Node target(new State(2,0,4,3));
    int cost = 0;
    int bfsCost = tree.bfs(&target);
    int dfsCost = tree.dfs(&target, tree.getRoot(), depth_limit, 0, cost);
    int iterativeCost = tree.iterativeDeepening(&target, depth_limit);
    
    std::cout << "BFS: " << bfsCost << std::endl;
    std::cout << "DFS: " << dfsCost << std::endl;
    std::cout << "Iterative Deepening: " << iterativeCost << std::endl;

    return 0;
}