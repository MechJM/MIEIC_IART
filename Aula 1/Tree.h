#include "Node.h"
#include <vector>

class Tree
{
    private:
    Node* root;


    public:
    std::vector<Node*> bfs(Node* target);
    std::vector<Node*> dfs(Node* target, int depth_limit);
    std::vector<Node*> iterativeDeepening(Node* target, int depth_limit);
};