#include "BinomialTree.hpp"
#include "common.hpp"
#include <list>


class BinomialHeap {
private:



public:
    BinomialHeap();
    std::list<Node*> roots;

};

BinomialHeap makeHeap() {
    return BinomialHeap();
}