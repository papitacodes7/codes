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

private:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    Node* addTwoLists(Node* head1, Node* head2) {

        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node* dummy = new Node(0);
        Node* curr = dummy;

        while (head1 || head2 || carry) {
            int sum = carry;

            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }

            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            curr->next = new Node(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        Node* result = reverse(dummy->next);

        // remove leading zeros
        while (result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }
};

// Utility function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First number: 456
    Node* head1 = new Node(4);
    head1->next = new Node(5);
    head1->next->next = new Node(6);

    // Second number: 12
    Node* head2 = new Node(1);
    head2->next = new Node(2);

    Solution obj;
    Node* result = obj.addTwoLists(head1, head2);

    cout << "Result: ";
    printList(result);

    return 0;
}


//we know how to rev a ll so basically + krna right se shuru hota he na ki left se toh rev krdenge dono ll ko and now.. we have to maintain sum and carry..and like hum also ek new dummy node bhi bana lenge and starting me jo zero se intialize krdenge now..and yeah hume iss ll named dummy ko bhi last me revv krna hi he toh curr krke start me rkh denge..like Node curr = dummy.. and now while tb tk chelga jabtk head1 he head2 he and carry he.. and also carry ko initialize zero se krenge.. and woh jo new node banynge na dummy naam se usse initialize krne ke liye starting me zero daal diya..kyuki last me toh result me reverse(dummy->next) hi bhjenge.. curr->next = new Node(sum % 10);
            // carry = sum / 10;
            // curr = curr->next; yaha pe hum curr->next me hi digit rkh reh hein..and fir curr->next but isse pehle update carry.. jo last wala while hoga usme hum jo starting me bekar zero aaye hue honge unhe hta denge..and in the end return result.


//Since addition of numbers always starts from the rightmost digit, but the given linked lists store the most significant digit at the head, we first reverse both linked lists to make addition easier. After reversing, we maintain a carry initialized to 0 and create a dummy node initialized with 0 to build the result list easily, using a pointer curr that starts at the dummy node. We then iterate while at least one of the lists still has nodes or a carry exists, and in each iteration we add the current digits of both lists (if present) along with the carry to compute the sum. A new node storing sum % 10 is attached to curr->next, the carry is updated as sum / 10, and curr is moved forward. Since the result is formed in reverse order, we reverse the result list at the end and remove any leading zeros if present, finally returning the head of the resulting linked list.



// skipped 9th one.. do it later.

