#ifndef BINOMIAL_TREE_HPP
#define BINOMIAL_TREE_HPP

#include "common.hpp"

struct Node {
    Node* parent;
    int key;
    int degree;
    Node* child;
    Node* sibling;
};


struct BinomialTree {

    Node* root;
};

#endif // BINOMIAL_TREE_HPP