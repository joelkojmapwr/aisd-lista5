#include "Graph.hpp"

Graph::Graph(int n, int m) {
    nrOfEdges = m;
    nrOfVertices = n;

    edges.resize(m);
}



bool edgeCompare(const Edge& a, const Edge& b) {
    if (a.weight < b.weight) {
        return true;
    } else if (a.weight == b.weight) {
        return a.vertices[0] < b.vertices[1];
    } else {
        return false;
    }
}

void Edge::print() {
    // std::cout << "Edge (" << vertices[0] << "," << vertices[1] << ")=" << weight << std::endl;
    std::cout << vertices[0] << " " << vertices[1] << " " << weight << std::endl;
}