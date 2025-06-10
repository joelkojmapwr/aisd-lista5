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