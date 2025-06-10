#ifndef COMMON
#define COMMON

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int currentCompareCounter = 0;

bool isGreater(int a, int b);
bool equals(int a, int b);
bool isGreaterOrEqual(int a, int b);

std::vector<int> randomPermutation(int n);

#endif