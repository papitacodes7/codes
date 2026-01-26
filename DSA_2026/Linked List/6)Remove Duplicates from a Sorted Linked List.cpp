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
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;

        while (curr->next != NULL) {
            if (curr->data == curr->next->data) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
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
    // Create sorted linked list: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);

    Solution obj;
    head = obj.removeDuplicates(head);

    printList(head);  // Output: 1 2 3 4

    return 0;
}


// Kyuki linked list **already sorted** hai, isliye jo bhi duplicates honge wo **hamesha adjacent nodes** me hi milenge. Hum ek pointer `curr` se list ko traverse karte hain aur har node ko uske next node se compare karte hain. Agar `curr->data` aur `curr->next->data` same ho, toh duplicate node ko skip kar dete hain by changing `curr->next` to `curr->next->next`. Agar values different ho, toh `curr` ko aage move kar dete hain. Is process ko end tak repeat karne se saare duplicates remove ho jaate hain bina extra space use kiye.
