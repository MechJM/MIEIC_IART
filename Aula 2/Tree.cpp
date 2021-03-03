#include "Tree.h"

Tree::Tree(Node* root)
{
    this->root = root;
}

int Tree::bfs(Node* target)
{
    int cost = 0;
    std::queue<Node*> toProcess;
    root->visited = true;
    toProcess.push(root);
    while (!toProcess.empty())
    {
        auto currentNode = toProcess.front();
        toProcess.pop();

        if ((*currentNode) == (*target))
        {
            break;;
        }

        for (auto childNode : currentNode->getChildren())
        {
            if (!childNode->visited)
            {
                childNode->visited = true;
                toProcess.push(childNode);
            }
        }
        cost++;
    }

    return cost;
}

int Tree::dfs(Node* target, Node* current_node, int depth_limit, int current_depth, int &cost)
{
    if (current_depth > depth_limit)
    {
        return -1;
    }

    if ((*current_node) == (*target))
    {
        return cost;
    } 

    current_node->visited = true;
    int current_cost;
    for (auto childNode : current_node->getChildren())
    {
        if (!childNode->visited)
        {
            current_cost = dfs(target, childNode, depth_limit, current_depth + 1, ++cost);
            if (current_cost >= 0) return cost;
        }
    }

    return -1;
}

int Tree::iterativeDeepening(Node* target, int depth_limit)
{
    int cost = 0, current_cost = 0;
    for (int i = 0; i <= depth_limit; i++)
    {
        cost += dfs(target, root, i, 0, current_cost);
    }

    if (cost < 0) cost = -1;

    return cost;
}


Node* Tree::getRoot()
{
    return root;
}
