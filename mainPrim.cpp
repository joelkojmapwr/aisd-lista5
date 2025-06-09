#include "common.hpp"
#include "prim.hpp"

int main() {
    int n;
    std::cin >> n;
    int m = (n*(n-1))/2;
    // std::cout << "M = " << m << std::endl;
    std::cout << n << std::endl;

    std::vector<std::pair<int, float>> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        float w;
        std::cin >> u >> v >> w;
        // graph.edges[i].print();
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w)); // since the graph is undirected
    }

    std::vector<Edge> mstEdges = primMST(n, m, adj);

    // std::cout << "Len of mstEdges: " << mstEdges.size() << std::endl;

    for (Edge e : mstEdges) {
        e.print();
    }
}