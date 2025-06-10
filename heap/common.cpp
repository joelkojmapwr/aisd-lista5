#include "common.hpp"


int currentCompareCounter = 0;

bool isGreater(int a, int b) {
    currentCompareCounter++;
    return a > b;
}

bool equals(int a, int b) {
    currentCompareCounter++;
    return a == b;
}

bool isGreaterOrEqual(int a, int b) {
    currentCompareCounter++;
    return a >= b;
}

std::vector<int> randomPermutation(int n) {
    std::vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(perm.begin(), perm.end(), g);
    return perm;
}