#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        // No loop
        if (slow != fast) return;

        // Step 2: Find start of loop
        slow = head;

        // Loop starts at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }

        // Loop starts elsewhere
        Node* prev = NULL;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
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
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    obj.removeLoop(head);

    // Print list after removing loop
    printList(head);

    return 0;
}


//Hum pehle Floyd’s cycle detection use karte hain jisme slow pointer 1 step aur fast pointer 2 steps chalta hai; agar dono kahin mil jaate hain toh loop exist karta hai. Loop milne ke baad slow ko head par reset kar dete hain, kyunki Floyd’s logic ke according slow aur fast ab dono same speed se chalenge aur loop ke starting node par milenge. Agar dono turant head par hi mil jaayein, iska matlab loop head se start ho raha hai, toh fast ko loop ke last node tak le jaakar uska next = NULL kar dete hain. Warna, slow aur fast ko saath-saath move karte hue fast ke previous node ko track karte hain aur jaise hi slow aur fast loop start par milte hain, us previous node ka next = NULL karke cycle tod dete hain. Is tarah bina extra space use kiye, har possible case me loop safely remove ho jaata hai.

