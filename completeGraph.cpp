#include "completeGraph.hpp"
#include <iostream>
#include <random>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage - give as input number of vertices and i will generate the edges with weights from (0, 1)" << std::endl;
        return 0;
    }

    int n = std::stoi(argv[1]);
    // std::cout << n;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            float w = getRandom();
            std::cout << i << " " << j << " " << w << std::endl; // edge from i to j with weight w
        }
    }

    return 0;
}