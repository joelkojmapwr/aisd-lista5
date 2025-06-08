#include <vector>

class Graph
{
private:
    
public:
    int nrOfEdges;
    int nrOfVertices;

    std::vector<Edge> edges;
    
    Graph(int n, int m);
    ~Graph();
};

struct Edge {
    int vertices[2];
    float weight;
};