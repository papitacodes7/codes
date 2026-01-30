#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool isCircular(Node *head) {
        if (head == NULL)
            return true;   // as per your logic

        Node* curr = head->next;

        while (curr != NULL && curr != head) {
            curr = curr->next;
        }

        return (curr == head);
    }
};

int main() {
    // Example 1: Circular Linked List
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head; // making it circular

    Solution sol;
    cout << sol.isCircular(head) << endl; // expected output: 1 (true)

    // Example 2: Non-circular Linked List
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    cout << sol.isCircular(head2) << endl; // expected output: 0 (false)

    // Example 3: Empty list
    Node* head3 = NULL;
    cout << sol.isCircular(head3) << endl; // returns 1 (true) as per your logic

    return 0;
}


//Start traversing from head->next.
// If traversal reaches head again, the linked list is circular; otherwise, if it reaches NULL, it is not.

