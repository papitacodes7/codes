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
    Node* intersectPoint(Node* head1, Node* head2) {

        // Step 1: Calculate lengths
        int len1 = 0, len2 = 0;
        Node* a = head1;
        Node* b = head2;

        while (a) {
            len1++;
            a = a->next;
        }
        while (b) {
            len2++;
            b = b->next;
        }

        // Step 2: Align both pointers
        a = head1;
        b = head2;

        int diff = abs(len1 - len2);

        if (len1 > len2) {
            while (diff--) a = a->next;
        } else {
            while (diff--) b = b->next;
        }

        // Step 3: Move together until intersection
        while (a && b) {
            if (a == b) {
                return a;  // intersection node
            }
            a = a->next;
            b = b->next;
        }

        return NULL; // guaranteed intersection exists
    }
};

int main() {
    /*
        Creating Y-shaped linked list

        head1: 10 -> 15 \
                          -> 30
        head2: 3 -> 6 -> 9 /
    */

    // Common part
    Node* common = new Node(15);
    common->next = new Node(30);

    // First list
    Node* head1 = new Node(10);
    head1->next = common;

    // Second list
    Node* head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = common;

    Solution obj;
    Node* intersection = obj.intersectPoint(head1, head2);

    if (intersection)
        cout << "Intersection Point: " << intersection->data << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}


// isme apan dono ll ka diff nikalana he.. and fir check krna he ki konsi ll bdi he. jobhi bdi he utna diff minus krna he.. and fir dono saath me chalane he jaha pe bhi mil jaaye wha pr intersection mil jyga..


//Since both linked lists intersect at a common node, the nodes after the intersection are shared. We first calculate the length difference of both linked lists and identify which list is longer. The pointer of the longer list is moved ahead by the difference in lengths so that both pointers are at the same distance from the intersection. Then both pointers are moved together one step at a time, and the node at which they meet is the intersection point.

