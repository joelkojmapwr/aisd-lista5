#include "kruskal.hpp"

std::vector<Edge> kruskal(Graph graph) {
    int n = graph.nrOfVertices;
    int m = graph.nrOfEdges;
    std::vector<Edge> mstEdges;
    std::sort(graph.edges.begin(), graph.edges.end(), &edgeCompare);
    // std::cout << "M=" <<m << std::endl;
    for (int i = 0; i < m; i++) {
        graph.edges[i].print();
    }

    DisjointSet set(n);
    mstEdges.reserve(n);
    // mstEdges.push_back(Edge{2, 3, 4.3});
    // std::cout << "Len of mstEdges: " << mstEdges.size();

    for (Edge edge : graph.edges) {
        int root_u = set.find(edge.vertices[0]);
        int root_v = set.find(edge.vertices[1]);
        if (root_u != root_v) {
            mstEdges.push_back(edge);
            set.uni(root_u, root_v);
        }
    }
    std::cout << "MST Edges: " << std::endl;
    for (Edge edge : mstEdges) {
        edge.print();
    }

    return mstEdges;
}