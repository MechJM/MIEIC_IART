#include "Tree.h"
#include <iostream>

int main()
{
    std::vector<std::vector<unsigned>> matrix = {{1,2,3},{5,0,6},{4,7,8}};
    std::vector<std::vector<unsigned>> targetMatrix = {{1,2,3},{4,5,6},{7,8,0}};
    printf("Im here\n");
    State* treeRootState = new NPuzzleState(matrix);
    Node treeRoot(treeRootState);
    printf("Im here2\n");
    Tree tree(&treeRoot);
    printf("Im here3\n");
    State* targetState = new NPuzzleState(targetMatrix);
    Node target(targetState);
    printf("Im here4\n");
    int cost = tree.bfs(&target);
    printf("Im here5\n");
    std::cout << "BFS: " << cost << "\n";
    printf("Im here6\n");
    return 0;
}