#include <bits/stdc++.h>
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

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (head == NULL) return NULL;

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;

        // Reverse first k nodes
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // head is now the last node of this group
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // prev is the new head of this group
        return prev;
    }
};

// Utility function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1->2->3->4->5->6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 3;

    Solution obj;
    head = obj.reverseKGroup(head, k);

    printList(head);   // Output: 3 2 1 6 5 4

    return 0;
}



// Pehle hum linked list ke first k nodes ko reverse karte hain using curr, prev, aur next.
// Reverse hone ke baad, jo head tha (pehla node), ab last node ban jaata hai is group ka.

// Ab bachi hui list (k+1)th node se) par same function ko recursively call kar dete hain.
// Jo recursive call se head milta hai, usko current group ke tail (head) se connect kar dete hain using
// head->next = reverseKGroup(curr, k).

// Har recursive call me head naya hota hai, lekin process same rehta hai —
// reverse first k nodes, phir baaki list par recursion, aur groups ko connect kar do.