#include <bits/stdc++.h>
using namespace std;

// Definition of linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to move last node to front
Node* moveToFront(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* curr = head;

    // Traverse to second last node
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    Node* last = curr->next;  // last node
    curr->next = NULL;        // break second last -> last
    last->next = head;        // attach last before head

    return last;              // new head
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = moveToFront(head);

    cout << "After Moving Last to Front: ";
    printList(head);

    return 0;
}


//To move the last node of a singly linked list to the front, we first traverse the list to reach the second last node, since only it can break the connection with the last node. Once the second last node is identified, we detach the last node by setting the second last node’s next pointer to NULL. Then, we connect the last node to the current head of the list and return it as the new head. This rearranges the list without creating any new nodes and preserves the order of the remaining elements.

//⏱️ Time & Space Complexity

// Time Complexity: O(n)
// (Single traversal to reach the second last node)

// Space Complexity: O(1)
// (Only pointer manipulation, no extra space)

