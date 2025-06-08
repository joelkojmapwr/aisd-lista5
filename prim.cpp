#include "prim.hpp"

std::vector<Edge> primMST(Graph &graph) {
    int n = graph.nrOfVertices;
    int m = graph.nrOfEdges;
    std::vector<Edge> mstEdges;

    std::vector<std::pair<int, float>> adj[n];

    for (int i = 0; i < m; i++ ) {
        int u = graph.edges[i].vertices[0];
        int v = graph.edges[i].vertices[1];
        float w = graph.edges[i].weight;
        // graph.edges[i].print();
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //                       (weight, direction, parent)
    std::priority_queue<std::tuple<float, int, int>, std::vector<std::tuple<float, int, int>>, std::greater<std::tuple<float, int, int>>> pq;

    std::vector<bool> visited(n, false);

    // Start from vertex 0
    pq.push(std::make_tuple(0, 0, -1));

    while(!pq.empty()) {
        auto p = pq.top();

        pq.pop();
        float w = std::get<0>(p);
        int u = std::get<1>(p);
        int parent = std::get<2>(p);

        if (visited[u] == true) {
            continue;
        }
        visited[u] = true;
        for (auto v : adj[u]) {
            if (visited[v.first] == false) {
                pq.push(std::make_tuple(v.second, v.first, u));
            }
        }
        if (parent != -1) {
            if (u < parent) {
                mstEdges.push_back(Edge{{u, parent}, w});
            } else {
                mstEdges.push_back(Edge{{parent, u}, w});
            }
        }
        
    }
    return mstEdges;
}