#include "BinomialHeap.hpp"

int n;

int main() {
    std::cin >> n;
    BinomialHeap H1 = makeHeap();
    BinomialHeap H2 = makeHeap();
    std::vector<int> perm = randomPermutation(2*n);
    for (int i = 0; i < n; i++) {
        H1.insert(perm[i]);
        H2.insert(perm[2*i]);
    }

    H1.uni(H2);
    int previousMin = -1;
    for (int i = 0; i < 2*n; i++) {
        Node* minNode = H1.extractMin();
        if (minNode == nullptr) {
            std::cout << "Heap is empty!" << std::endl;
            return 0;
        }
        std::cout << minNode->key << " ";
        if (minNode->key < previousMin) {
            std::cout << "Error: extracted minimum is less than the previous minimum!" << std::endl;
            return 1;
        }
        previousMin = minNode->key;
        delete minNode; // Clean up the extracted node
    }
}