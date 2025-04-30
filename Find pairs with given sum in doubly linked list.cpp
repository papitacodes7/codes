#include <iostream>
#include <vector>
using namespace std;

// Definition of a doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Helper function to print pairs
void printPairs(const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
}

int main() {
    // Create a sorted doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    // Find pairs with sum 5
    vector<pair<int, int>> pairs = findPairs(head, 5);

    // Print the pairs
    printPairs(pairs);

    return 0;
}

//comments-
// This code defines a doubly linked list and finds pairs of nodes that sum to a given value.
// The function `findPairs` takes the head of the list and the target sum as input and returns a vector of pairs.