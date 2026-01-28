#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {

        Node* dummy = new Node(0);
        Node* curr = dummy;

        Node* p1 = head1;
        Node* p2 = head2;

        while (p1 && p2) {
            if (p1->data == p2->data) {
                curr->next = new Node(p1->data);
                curr = curr->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->data < p2->data) {
                p1 = p1->next;
            }
            else {
                p2 = p2->next;
            }
        }

        return dummy->next;
    }
};

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // LinkedList1: 1 -> 2 -> 3 -> 4 -> 6
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    // LinkedList2: 2 -> 4 -> 6 -> 8
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Solution obj;
    Node* result = obj.findIntersection(head1, head2);

    cout << "Intersection: ";
    printList(result);

    return 0;
}


//sorted ll given he dono.. now we have to use pointer approach p1 rkhenge head1 pe p2 rkhenge head2 pe.. now if p1->data == p2->data.. so we have to just make a new dummy node and usme daal ke next fir pnext dono.. if p1data<p2 toh p1next warna p2 next.. last me returnn dummy->next; that's it.. make sure to initialize dummy in the first.. that's it..

//Since both linked lists are sorted, we use a two-pointer approach where pointer p1 starts at head1 and pointer p2 starts at head2. If p1->data is equal to p2->data, this value belongs to the intersection, so we create a new node and attach it to a dummy list, then move both pointers to their next nodes. If p1->data is smaller than p2->data, we move p1 forward; otherwise, we move p2 forward. We initialize a dummy node at the beginning to simplify result list creation, and finally return dummy->next as the head of the intersection list.

