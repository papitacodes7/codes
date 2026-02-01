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
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int, int>> ans;
        if (!head) return ans;

        Node* left = head;
        Node* right = head;

        // move right to last node
        while (right->next != NULL) {
            right = right->next;
        }

        // two-pointer approach
        while (left != right && left->prev != right) {

            int sum = left->data + right->data;

            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};

// Utility to print pairs
void printPairs(vector<pair<int,int>> &v) {
    for (auto &p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
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

    int target = 7;

    Solution obj;
    vector<pair<int,int>> res = obj.findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ": ";
    printPairs(res);

    return 0;
}



// The idea is to use two pointers, one starting at the head and the other at the end of the sorted doubly linked list. Move the first pointer forward if the sum of the two pointer's values is less than the target, or move the second pointer backward if the sum is greater. Continue until the pointers meet or cross each other.