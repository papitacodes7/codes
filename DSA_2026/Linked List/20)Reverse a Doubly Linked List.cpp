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
    Node* reverse(Node* head) {

        if (head == NULL || head->next == NULL)
            return head;

        Node* curr = head;
        Node* back = NULL;

        while (curr != NULL) {

            // store prev
            back = curr->prev;

            // swap prev and next
            curr->prev = curr->next;
            curr->next = back;

            // move forward (actually backward after swap)
            curr = curr->prev;
        }

        // new head
        return back->prev;
    }
};

// Utility function to print DLL
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create DLL: 1 <-> 2 <-> 3 <-> 4
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverse(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}



// Hum ek pointer curr se doubly linked list traverse karte hain. Har node ke liye, humein uske prev aur next pointers ko swap karna hota hai, bilkul waise hi jaise hum teen variables ka swap karte hain. Iske liye hum ek temporary pointer back use karte hain: pehle curr->prev ko back me store karte hain, phir curr->prev ko curr->next bana dete hain, aur curr->next ko back assign kar dete hain. Swap ke baad, original next node ab curr->prev ban jaata hai, isliye traversal ke liye hum curr = curr->prev move karte hain. Ye process poori list ke liye repeat hota hai, aur end me back->prev new head ko point karta hai, jisse reversed doubly linked list mil jaati hai.