#include "common.hpp"
#include "kruskal.hpp"

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    int m = (n*(n-1))/2;
    Graph graph(n, m);
    // std::cout << "M = " << m << std::endl;
    std::cout << n << std::endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        float w;
        std::cin >> u >> v >> w;
        graph.edges[i].vertices[0] = u;
        graph.edges[i].vertices[1] = v;
        graph.edges[i].weight = w;
        // graph.edges[i].print();
    }

    kruskal(graph);
}