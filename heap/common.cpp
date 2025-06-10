#include "common.hpp"

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