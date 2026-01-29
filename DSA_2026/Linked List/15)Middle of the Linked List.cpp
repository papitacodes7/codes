// https://leetcode.com/problems/middle-of-the-linked-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;   // 2 steps
        }
        return slow;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* mid = obj.middleNode(head);

    cout << "Middle node value: " << mid->val << endl;

    return 0;
}

//In this solution, the slow–fast pointer technique is used to find the middle of a singly linked list efficiently. Two pointers are initialized at the head of the list: slow and fast. In each iteration, slow moves one step forward while fast moves two steps forward. Because fast moves twice as fast, it reaches the end of the list when slow is at the middle. The loop continues as long as fast and fast->next are not null, ensuring safe traversal. This approach works in a single pass, does not modify the original list, uses constant extra space, and correctly returns the second middle node in case of an even-length list.



//apne isme na merge sort and quick sort using ll skipped on 29/1/26 ye leetcode wala he..

