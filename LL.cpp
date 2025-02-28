#include <bits/stdc++.h>
using namespace std;

// Definition for a singly-linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert at a specific position (1-based index)
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at a specific position (1-based index)
void deleteNode(Node*& head, int pos) {
    if (head == nullptr) return;
    Node* temp = head;
    if (pos == 1) {
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

// Function to search for a value in the linked list
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = nullptr;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    printList(head); // Output: 10 -> 20 -> 30 -> NULL

    insertAtHead(head, 5);
    printList(head); // Output: 5 -> 10 -> 20 -> 30 -> NULL

    insertAtPosition(head, 25, 3);
    printList(head); // Output: 5 -> 10 -> 25 -> 20 -> 30 -> NULL

    deleteNode(head, 2);
    printList(head); // Output: 5 -> 25 -> 20 -> 30 -> NULL

    cout << "Search 20: " << (search(head, 20) ? "Found\n" : "Not Found\n"); // Found
    cout << "Search 100: " << (search(head, 100) ? "Found\n" : "Not Found\n"); // Not Found

    return 0;
}
