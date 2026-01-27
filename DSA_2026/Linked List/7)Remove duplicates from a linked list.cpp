#include <bits/stdc++.h>
using namespace std;

// Definition of Linked List Node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to remove duplicates from UNSORTED linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL) return head;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        // Duplicate found
        if (seen.count(curr->data)) {
            prev->next = curr->next;
        }
        // First occurrence
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Creating list: 5 -> 2 -> 2 -> 4
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}

//To remove duplicates from an unsorted linked list, we traverse the list once while maintaining a hash set to store values that have already been seen. For each node, if its value exists in the set, the node is a duplicate and is removed by updating the previous node’s next pointer to skip the current node. If the value is not present, it is inserted into the set and the node is kept as part of the list by moving the prev pointer forward. This approach ensures that only the first occurrence of each value is retained while preserving the original order of the linked list.

// ⏱️ Time & Space Complexity
// Time Complexity: O(n)
// (Each node is visited once, and set operations are O(1) on average)

// Space Complexity: O(n)
// (Extra space for storing up to n elements in the hash set)