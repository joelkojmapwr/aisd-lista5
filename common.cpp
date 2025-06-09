#include "common.hpp"


float getRandom() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    float newRandom = dis(gen);
    while (newRandom == 0.0)
    {
        newRandom = dis(gen);
    }
    return newRandom;
}

int randomInt(int start, int end) {
    float randFloat = getRandom();
    int intervalLength = end - start + 1;
    return start + static_cast<int>(randFloat * intervalLength);
}

DisjointSet::DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0 ; i<n ; i++) {
        parent[i] = i;
    }
}

int DisjointSet::find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

void DisjointSet::uni(int root1, int root2) {
    if(rank[root1] > rank[root2]) {
        parent[root2] = root1;
    } else if (rank[root1] < rank[root2]) {
        parent[root1] = root2;    
    } else {
        parent[root2] = root1;
        rank[root1]++;
    }
}