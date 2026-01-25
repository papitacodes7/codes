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
    bool detectLoop(Node* head) {
        if (head == NULL) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps

            if (slow == fast) {
                return true;             // loop detected
            }
        }
        return false;                    // no loop
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop: 5 -> 2
    head->next->next->next->next->next = head->next;

    Solution obj;

    if (obj.detectLoop(head))
        cout << "Loop detected" << endl;
    else
        cout << "No loop" << endl;

    return 0;
}


//Slow pointer ek step aur fast pointer do step move karta hai.
// Loop hone par fast slow ko catch kar leta hai, warna fast NULL ho jaata hai.