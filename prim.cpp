#include "prim.hpp"

float minKey(std::vector<float> &key, std::vector<bool> &visited) {
    float min = std::numeric_limits<float>::max();
    int minIndex = -1;

    for (int v = 0; v < key.size(); v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}


std::vector<Edge> primMST(int n, int m, std::vector<std::pair<int, float>> adj[]) {
    std::vector<Edge> mstEdges;
    
    std::vector<bool> visited(n, false);
    std::vector<float> key(n, std::numeric_limits<float>::max());
    key[0] = 0; // Start from vertex 0, set its key to 0
    std::vector<int> parent(n); // To store the parent of each vertex in the MST
    parent[0] = -1; // The first vertex has no parent

    for (int i=0; i<n; i++) {
        int u = minKey(key, visited);
        int uParent = parent[u];
        float w = key[u];
        visited[u] = true;
        if (uParent != -1) { // if this is root don't add to list
            if (uParent < u) {
                mstEdges.push_back(Edge{uParent, u, w});
            } else {
                mstEdges.push_back(Edge{u, uParent, w});
            }
        }
        
        
        for (auto &v : adj[u]) {
            if (visited[v.first] == false && v.second < key[v.first]) {
                key[v.first] = v.second; // Update the key value
                parent[v.first] = u; // Update the parent
            }
        }
    }
    // std::cout << "Len of mstedges: " << mstEdges.size() << std::endl;
    return mstEdges;
}