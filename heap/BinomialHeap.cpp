#include "BinomialHeap.hpp"
BinomialHeap::BinomialHeap() {
    // Initialize an empty binomial heap
    roots = std::list<Node*>();
    std::cout << "Initialized heap with roots size: " << roots.size() << std::endl;
}

BinomialHeap::~BinomialHeap() {
    // Destructor to clean up the heap
    for (Node* root : roots) {
        delete root; // Assuming nodes are dynamically allocated
    }
    roots.clear();
    std::cout << "Destroyed heap with roots size: " << roots.size() << std::endl;
}

Node* BinomialHeap::minimum() {
    if (roots.empty()) {
        return nullptr; // No elements in the heap
    }
    
    Node* minNode = roots.front();
    for (Node* node : roots) {
        if (isGreater(minNode->key, node->key)) {
            minNode = node;
        }
    }
    
    return minNode; // Return the node with the minimum key
}

void BinomialHeap::link(Node* y, Node* z) {
    
    if (isGreater(z->key, y->key)) {
        std::swap(y, z);
    }
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

void BinomialHeap::merge(BinomialHeap inputHeap) {
    std::list<Node*> newRoots = std::list<Node*>();
    int i=0;
    while (roots.front() != nullptr && inputHeap.roots.front() != nullptr) {
        Node* newRoot = nullptr;
        if (roots.front()->degree <= inputHeap.roots.front()->degree) {
            newRoot = roots.front();
            roots.pop_front();
        } else {
            newRoot = inputHeap.roots.front();
            inputHeap.roots.pop_front();
        }
        if (i >= 1) {
            newRoots.back()->sibling = newRoot;
        }
        newRoots.push_back(newRoot);
        i++;
    }
    while (roots.front() != nullptr) {
        if (i >= 1) {
            newRoots.back()->sibling = roots.front();
        }
        newRoots.push_back(roots.front());
        roots.pop_front();
        i++;
    }
    while (inputHeap.roots.front() != nullptr) {
        if (i >= 1) {
            newRoots.back()->sibling = inputHeap.roots.front();
        }
        newRoots.push_back(inputHeap.roots.front());
        inputHeap.roots.pop_front();
        i++;
    }
    if (!newRoots.empty()) {
        newRoots.back()->sibling = nullptr; // Ensure the last node's sibling is nulls
    }
    roots = newRoots;
}

BinomialHeap makeHeap() {
    return BinomialHeap();
}

void BinomialHeap::uni(BinomialHeap inputHeap) {
    merge(inputHeap);
    if (roots.empty()) {
        return; // Nothing to do if the heap is empty
    }

}