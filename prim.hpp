#include "common.hpp"
#include "Graph.hpp"
#include <queue>
#include <tuple>

std::vector<Edge> primMST(int n, int m, std::vector<std::pair<int, float>> adj[]);
float minKey(std::vector<float> &key, std::vector<bool> &visited);