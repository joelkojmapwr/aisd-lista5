#include "BinomialHeap.hpp"
BinomialHeap::BinomialHeap() {
    // Initialize an empty binomial heap
    roots = std::list<Node*>();
    std::cout << "Initialized heap with roots size: " << roots.size() << std::endl;
}