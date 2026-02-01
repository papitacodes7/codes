#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) 
    {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
};

int countAllTripletSum(Node *head, int x)
{
    if (head == NULL) return 0;

    int count = 0;

    // Find tail
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Fix first element
    for (Node* curr = head; curr != NULL && curr->next != NULL; curr = curr->next) {

        Node* left = curr->next;
        Node* right = tail;

        while (left != NULL && right != NULL &&
               left != right && right->next != left) {

            int sum = curr->data + left->data + right->data;

            if (sum == x) {
                count++;
                left = left->next;
                right = right->prev;
            }
            else if (sum < x) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }
    }

    return count;
}

// Utility to print DLL
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create sorted DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
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

    cout << "DLL: ";
    printList(head);

    int x = 10;
    cout << "Triplet count with sum " << x << ": ";
    cout << countAllTripletSum(head, x) << endl;

    return 0;
}


//https://www.naukri.com/code360/problems/count-triplets_873377

// Since the doubly linked list is sorted, we use a three-pointer approach to count all triplets with a given sum. We fix one pointer curr as the first element of the triplet, and then apply a two-pointer technique using left and right on the remaining part of the list to find pairs whose sum equals x - curr->data. The left pointer moves forward to increase the sum, while the right pointer moves backward to decrease the sum. This process is repeated for each fixed node until all valid triplets are counted.

// ⏱️ Time Complexity

// O(n²) — one loop to fix the first element and an inner two-pointer traversal for the remaining list.

// 📦 Space Complexity

// O(1) — only pointers are used; no extra data structures.