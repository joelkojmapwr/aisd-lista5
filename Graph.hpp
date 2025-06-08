#include <vector>
#include "common.hpp"

struct Edge {
    int vertices[2];
    float weight;
    void print();
};
class Graph
{
private:
    
public:
    int nrOfEdges;
    int nrOfVertices;

    std::vector<Edge> edges;
    
    Graph(int n, int m);
};



bool edgeCompare(const Edge& a, const Edge& b);