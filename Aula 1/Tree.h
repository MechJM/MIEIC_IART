#include "Node.h"
#include <vector>
#include <queue>

class Tree
{
    private:
    Node* root;

    public:
    Tree(Node* root);
    int bfs(Node* target);
    int dfs(Node* target, Node* current_node, int depth_limit, int current_depth, int &cost);
    int iterativeDeepening(Node* target, int depth_limit);
    Node* getRoot();
};