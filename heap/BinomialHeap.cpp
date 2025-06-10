#include "BinomialHeap.hpp"

extern int currentCompareCounter;

BinomialHeap::BinomialHeap() {
    // Initialize an empty binomial heap
    roots = std::list<Node*>();
    // std::cout << "Initialized heap with roots size: " << roots.size() << std::endl;
}

BinomialHeap::~BinomialHeap() {
    // Destructor to clean up the heap
    // for (Node* root : roots) {
    //     delete root; // Assuming nodes are dynamically allocated
    // }
    // roots.clear();
    // std::cout << "Destroyed heap with roots size: " << roots.size() << std::endl;
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

/**
 * Link y into z's Tree
 */
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
    // std::cout << "Merging heaps..." << std::endl;
    // plotHeap();
    // inputHeap.plotHeap();
    merge(inputHeap);
    if (roots.empty()) {
        return; // Nothing to do if the heap is empty
    }
    Node* prevX = nullptr;
    Node* x = roots.front();
    Node* nextX = x->sibling;
    while (nextX != nullptr) {
        if((x->degree != nextX->degree) || ((nextX->sibling != nullptr) && (nextX->sibling->degree == x->degree))) {
            prevX = x;
            x = nextX;
        } else {
            if (isGreaterOrEqual(nextX->key, x->key)) {
                x->sibling = nextX->sibling;
                link(nextX, x);
                roots.remove(nextX); // Remove nextX from the roots list
            } else {
                if (prevX == nullptr) {
                    roots.pop_front();
                } else {
                    prevX->sibling = nextX;
                }
                link(x, nextX);
                roots.remove(x); // Remove x from the roots list
                x = nextX;
            }
        }
        nextX = x->sibling;
    }
}

void BinomialHeap::printBinomialTree(Node* node, int level) {
        if (!node) return;

        // Print current node with indentation
        std::cout << std::string(level * 2, ' ') << "Key: " << node->key 
                  << " (Degree: " << node->degree << ")" << std::endl;

        // Recursively print children (child pointer points to leftmost child)
        Node* child = node->child;
        while (child) {
            printBinomialTree(child, level + 1);
            child = child->sibling;
        }
    }

void BinomialHeap::plotHeap() {
        if (roots.empty()) {
            std::cout << "Heap is empty" << std::endl;
            return;
        }

        std::cout << "Binomial Heap Structure:" << std::endl;
        int treeIndex = 0;
        for (Node* root : roots) {
            std::cout << "Tree " << treeIndex++ << " (Degree " << root->degree << "):" << std::endl;
            printBinomialTree(root);
            std::cout << std::endl;
        }
    }

void BinomialHeap::insert(int value) {
    // std::cout << "Inserting value: " << value << std::endl;
    Node* x = new Node();
    x->key = value;
    BinomialHeap H = makeHeap();
    x->parent = nullptr;
    x->child = nullptr;
    x->sibling = nullptr;
    x->degree = 0;
    H.roots.push_back(x);
    uni(H);
}

Node* findMinNode(std::list<Node*> nodes) {
    if (nodes.empty()){
        return nullptr;
    }
    Node* minNode = nodes.front();
    for (Node* node : nodes) {
        if (isGreater(minNode->key, node->key)) {
            minNode = node;
        }
    }
    return minNode;
}

Node* BinomialHeap::extractMin() {
    Node* x = findMinNode(roots);
    if (x == nullptr) {
        return nullptr; // No elements in the heap
    }
    auto it = std::find(roots.begin(), roots.end(), x);
    Node* prevX = nullptr;
    if (it != roots.begin()) {
        prevX = *std::prev(it);
        if (it!= roots.end()) {
            prevX->sibling = x->sibling; // Set the previous node's sibling to x's sibling
        } else {
            prevX->sibling = nullptr; // If x is the last node, set sibling to nullptr
        }
    }
    
    roots.remove(x); // Remove x from the roots list
    if (x->child == nullptr) {
        return x; // If x has no children, return it
    }
    // If x has children, we need to add them to the roots list
    std::list<Node*> children = std::list<Node*>();
    Node* child = x->child;
    while (child != nullptr) {
        Node* nextChild = child->sibling; // Save the next child
        // child->sibling = nullptr; // Remove the sibling link
        children.push_front(child); // Add to the front of the list
        child = nextChild; // Move to the next child
    }
    BinomialHeap H = makeHeap();
    for (auto it = children.begin(); it != children.end(); ++it) {
        (*it)->parent = nullptr; // Set parent to nullptr
        if (std::next(it) != children.end()) {
            (*it)->sibling = *std::next(it); // Set sibling to the next child
        } else {
            (*it)->sibling = nullptr; // Last child has no sibling
        }
        H.roots.push_back(*it); // Add child to the new heap
    }
    uni(H); // Merge the new heap with the current heap
    return x; // Return the extracted minimum node
}

bool BinomialHeap::isEmpty() {
    return roots.empty();
}