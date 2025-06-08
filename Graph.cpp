#include "Graph.hpp"

Graph::Graph(int n, int m) {
    nrOfEdges = m;
    nrOfVertices = n;

    edges.resize(m);
}