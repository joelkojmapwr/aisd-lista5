#include "common.hpp"
#include "Graph.hpp"
#include <stack>
#include <algorithm>

int n;

struct Node {
    int id;
    int complexity;
    std::vector<Node*> children;
};

void printOrderAndCost(Node* root) {
    if (!root || root->id == -1) return;
    std::cout << "Node: " << root->id << ", Cost: " << root->complexity << " ChildrenOrder: ";
    for (auto child : root->children){
        std::cout << child->id << " ";
    }
    std::cout << std::endl;
    for (auto child : root->children) {
        printOrderAndCost(child);
    }
}



/**
 * Returns vector of children already sorted in calling order
 */
Node* getCallingOrder(int root, std::vector<std::vector<int>> &children) {
    // std::cout << "Processing node " << root << std::endl;
    int nrOfChildren = children[root].size();
    if (nrOfChildren == 0) {
        return new Node {root, 0, {}};
    }
    std::vector<Node*> order(nrOfChildren);
    for (int i = 0; i<nrOfChildren; i++) {
        // std::cout << "Processing child"
        Node* newChild = getCallingOrder(children[root][i], children);
        // std::cout << "Returned from function" << std::endl;
        order[i] = newChild;
    }
    // std::cout << "Before sort" <<std::endl;
    std::sort(order.begin(), order.end(), [](Node* a, Node* b) {
        return a->complexity > b->complexity;
    });
    // std::cout << "After sort" <<std::endl;
    int maxPropagationTime = 0;
    for (int i = 0; i<nrOfChildren; i++) {
        int childPropagationTime = order[i]->complexity + i + 1;
        maxPropagationTime = std::max(maxPropagationTime, childPropagationTime);
    }

    return new Node{root, maxPropagationTime, order};
}

int main() {

    std::cin >> n;
    // std::cout << "N=" << n << std::endl;
    std::vector<std::pair<int, float>> edges[n];

    for (int i=0; i<n-1; i++) {
        int v, u;
        float w;
        std::cin >> u >> v >> w;
        edges[u].push_back(std::make_pair(v, w));
        edges[v].push_back(std::make_pair(u, w));
    }

    int root = randomInt(0, n-1);
    // int root = 3;
    std::cout << "Chosen root: " << root << std::endl;

    std::vector<std::vector<int>> children(n);
    std::vector<int> parent(n, -2);
    
    parent[root] = -1;
    std::stack<int> toVisit;
    toVisit.push(root);
    while(toVisit.size() > 0) {
        int currentV = toVisit.top();
        toVisit.pop();
        for (auto neighbour : edges[currentV]) {
            if (parent[neighbour.first] == -2) { // this node is not yet initialized so adopt it to be my child
                // std::cout << "Pushing new neighbour" << std::endl;
                toVisit.push(neighbour.first);
                children[currentV].push_back(neighbour.first);
                parent[neighbour.first] = currentV;
            }
        }
    }
    for (int i=0; i<n; i++){
        std::cout << "Children of " << i << " ";
        for (auto child : children[i]) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
        std::cout << "Parent of " << i << " " << parent[i] << std::endl;
    }

    Node* rootNode = getCallingOrder(root, children);
    printOrderAndCost(rootNode);
}