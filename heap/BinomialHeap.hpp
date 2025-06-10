#include "BinomialTree.hpp"
#include "common.hpp"
#include <list>


class BinomialHeap {
private:



public:
    BinomialHeap();
    ~BinomialHeap();
    std::list<Node*> roots;
    Node* minimum();
    void link(Node* y, Node* z);
    void merge(BinomialHeap inputHeap);
    void uni(BinomialHeap inputHeap);
    void insert(Node* x);
};

BinomialHeap makeHeap();
