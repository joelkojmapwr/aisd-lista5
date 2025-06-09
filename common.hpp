#ifndef COMMON
#define COMMON

#include <random>
#include <iostream>

float getRandom();

int randomInt(int start, int end); // inclusive

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    DisjointSet(int n);
    int find(int v);
    void uni(int root1, int root2);
};

#endif