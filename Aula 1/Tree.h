#include "Node.h"
#include <vector>
#include <queue>

class Tree
{
    private:
    Node* root;
    std::vector<Node*> iterativeDeepeningAux(Node* target, int depth_limit, int current_depth);

    public:
    int bfs(Node* target);
    int dfs(Node* target, Node* current_node, int depth_limit, int current_depth, int &cost);
    std::vector<Node*> iterativeDeepening(Node* target, int depth_limit);
};