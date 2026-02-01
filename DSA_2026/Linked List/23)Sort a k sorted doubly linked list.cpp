#include <bits/stdc++.h>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        
        if (head == NULL) return head;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        DLLNode *temp1 = head;
        DLLNode *temp2 = head;

        while (temp1) {
            minHeap.push(temp1->data);

            if (minHeap.size() == k + 1) {
                temp2->data = minHeap.top();
                minHeap.pop();
                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }

        while (!minHeap.empty()) {
            temp2->data = minHeap.top();
            minHeap.pop();
            temp2 = temp2->next;
        }

        return head;
    }
};

// Utility to print DLL
void printList(DLLNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create k-sorted DLL: 3 <-> 6 <-> 2 <-> 12 <-> 56 <-> 8
    DLLNode* head = new DLLNode(3);
    DLLNode* n2 = new DLLNode(6);
    DLLNode* n3 = new DLLNode(2);
    DLLNode* n4 = new DLLNode(12);
    DLLNode* n5 = new DLLNode(56);
    DLLNode* n6 = new DLLNode(8);

    head->next = n2; n2->prev = head;
    n2->next = n3;   n3->prev = n2;
    n3->next = n4;   n4->prev = n3;
    n4->next = n5;   n5->prev = n4;
    n5->next = n6;   n6->prev = n5;

    int k = 2;

    cout << "Original DLL: ";
    printList(head);

    Solution obj;
    head = obj.sortAKSortedDLL(head, k);

    cout << "Sorted DLL:   ";
    printList(head);

    return 0;
}


// basically jo bhi k diya he utna hi ek number aage piche ho skta he.. so what we have to do is.. temp1 and temp2 head pe laga dene hein and minHeap me push krte jaana he temp1.. jabtk heap ka size k+1 tk nhi ho jaata now.. temp2 me minheap ka top daalna he.. min heap se woh nikaalna he.. and temp2 ko aage krdena he... repeat me.. temp1 last me pohnch jyga minheap me kuch daalne layak nhi rahega toh bass nikaalna rahega min heap me se toh..nikaal lenge.. temp2 me daalke pop fir temp2 aage.. and return krdenge head; that's it sort hogyi 



//Since the doubly linked list is k-sorted, each element is at most k positions away from its correct sorted position. Therefore, for any position in the list, the correct smallest element must lie within the next k+1 nodes. To efficiently place elements in order, we use a min-heap of size k+1. We traverse the list using one pointer to push elements into the heap and another pointer to overwrite the node data with the minimum element from the heap whenever its size becomes k+1. Once traversal ends, the remaining elements in the heap are extracted and placed into the list, resulting in a fully sorted doubly linked list.

// ⏱️ Time Complexity

// O(n log k) — each insertion and deletion from heap costs log k.

// 📦 Space Complexity

// O(k) — extra space used by the min-heap.