#ifndef BINOMIAL_HEAP
#define BINOMIAL_HEAP

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
    void insert(int value);
    Node* extractMin();
    void plotHeap() ;
    void printBinomialTree(Node* node, int level = 0);

    bool isEmpty();
};

BinomialHeap makeHeap();

Node* findMinNode(std::list<Node*> nodes);

#endif