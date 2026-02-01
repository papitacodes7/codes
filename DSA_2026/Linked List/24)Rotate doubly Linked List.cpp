#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        if (head == NULL || p == 0)
            return head;

        Node* curr = head;
        int len = 1;

        // Find length and tail
        while (curr->next != NULL) {
            curr = curr->next;
            len++;
        }
        Node* tail = curr;

        // Normalize p
        p = p % len;
        if (p == 0) return head;

        // Move to p-th node
        curr = head;
        for (int i = 1; i < p; i++) {
            curr = curr->next;
        }

        Node* newHead = curr->next;

        // Break list
        curr->next = NULL;
        newHead->prev = NULL;

        // Attach old head at end
        tail->next = head;
        head->prev = tail;

        return newHead;
    }
};

// Utility to print DLL
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    head->next = n2; n2->prev = head;
    n2->next = n3;   n3->prev = n2;
    n3->next = n4;   n4->prev = n3;
    n4->next = n5;   n5->prev = n4;
    n5->next = n6;   n6->prev = n5;

    int p = 2;

    cout << "Original DLL: ";
    printList(head);

    Solution obj;
    head = obj.rotateDLL(head, p);

    cout << "Rotated DLL:  ";
    printList(head);

    return 0;
}


//Basically, hum list me p nodes tak aage jaate hain aur (p+1)-th node ko new head bana dete hain. Phir p-th node ke baad se list ki connections break kar dete hain taaki pehla part alag ho jaaye. Uske baad hum list ke end tak jaakar tail nikaalte hain aur tail ke next ko purane head se connect kar dete hain. Saath hi, doubly linked list hone ki wajah se head ke prev ko tail se connect karte hain. Is tarah first p nodes list ke end me chale jaate hain aur list counter-clockwise rotate ho jaati hai.

//⏱️ Time Complexity

// O(n)

// List ko ek baar traverse karke length/tail nikaalte hain

// Aur ek baar p-th node tak jaate hain

// Total traversal linear hai.

// 📦 Space Complexity

// O(1)

// Sirf pointers use hue hain

// Koi extra data structure nahi use kiya

