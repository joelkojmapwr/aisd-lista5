#include "common.hpp"
#include "Graph.hpp"
#include <stack>

// void setupTree(std::vector<std::pair<int, float>> &edges[]);

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, float>> edges[n];

    for (int i=0; i<n-1; i++) {
        int v, u;
        float w;
        edges[u].push_back(std::make_pair(v, w));
        edges[v].push_back(std::make_pair(u, w));
    }

    int root = randomInt(0, n-1);
    std::cout << "Chosen root: " << root << std::endl;

    std::vector<int> children[n];
    std::vector<int> parent(n, -2);
    
    parent[root] = -1;
    std::stack<int> toVisit;
    toVisit.push(root);
    while(toVisit.size() > 0) {
        int currentV = toVisit.top();
        toVisit.pop();
        for (auto neighbour : edges[currentV]) {
            if (parent[neighbour.first] == -2) { // this node is not yet initialized so adopt it to be my child
                toVisit.push(neighbour.first);
                children[currentV].push_back(neighbour.first);
                parent[neighbour.first] = currentV;
            }
        }
    }
    // for (int i=0; i<n; i++){
    //     std::cout << 
    // }

}