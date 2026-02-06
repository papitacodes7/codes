// 34th question he ye .. supposed to do other's but kon kre feels tired..aj hi mid term of 6/2/26 finish hue so imma just do this for now today..

//https://leetcode.com/problems/odd-even-linked-list

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

// Helper: create linked list from vector
ListNode* createList(vector<int>& v) {
    if (v.empty()) return NULL;

    ListNode* head = new ListNode(v[0]);
    ListNode* curr = head;

    for (int i = 1; i < v.size(); i++) {
        curr->next = new ListNode(v[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode* head = createList(v);

    Solution sol;
    head = sol.oddEvenList(head);

    cout << "After odd-even rearrangement:\n";
    printList(head);

    return 0;
}


// basically odd pe jo he odd se connect kr odd.next = odd.next.next se.. same for even just even ko odd se ek kadam aage rkhna now.. odd ki tail ko even ke head se connect krde and you are done..


//Is problem me hume linked list ke nodes ko unke positions ke basis par rearrange karna hota hai, values ke basis par nahi. Hum do pointers maintain karte hain: odd jo odd position ke nodes ko track karta hai aur even jo even position ke nodes ko track karta hai. evenHead ko store karte hain taaki baad me even list ko odd list ke end me attach kar sakein. Traversal ke dauran, hum odd node ko agle odd node se aur even node ko agle even node se connect karte hain by skipping one node in between. Isse odd aur even indexed nodes alag-alag chains me aa jaate hain. Traversal ke baad, even list ko odd list ke end me attach kar diya jaata hai, jisse required rearranged list mil jaati hai.

// ⏱️ Time Complexity

// O(n) — linked list ka sirf ek traversal hota hai.

// 💾 Space Complexity

// O(1) — koi extra data structure use nahi hota, sirf pointers rearrange kiye jaate hain.