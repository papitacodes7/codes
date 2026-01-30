#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseList(Node* head) {

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {

        Node* nextNode = curr->next; // store next
        curr->next = prev;           // reverse link
        prev = curr;                 // move prev
        curr = nextNode;             // move curr
    }

    return prev; // new head
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseList(head);
    printList(head);

    return 0;
}
