#include "BinomialHeap.hpp"

int n;
extern int currentCompareCounter;

int main() {
    std::cin >> n;
    BinomialHeap H1 = makeHeap();
    BinomialHeap H2 = makeHeap();
    std::vector<int> perm = randomPermutation(2*n);
    for (int i = 0; i < n; i++) {
        H1.insert(perm[2*i + 1]);
        // H1.plotHeap();
        H2.insert(perm[2*i]);
        // H2.plotHeap();
    }

    H1.uni(H2);
    int previousMin = -1;
    for (int i = 0; i < n*2; i++) {
        // std::cout << "Extracting minimum from heap: ";
        Node* minNode = H1.extractMin();
        if (minNode == nullptr) {
            throw std::runtime_error("Error: Heap is empty!");
            return 0;
        }
        std::cout << minNode->key << " ";
        if (minNode->key < previousMin) {
            throw std::runtime_error("Error: extracted minimum is less than the previous minimum!");
            return 1;
        }
        previousMin = minNode->key;
        delete minNode; // Clean up the extracted node
    }
}