/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* slow = head;  // Slow pointer to find the node before the target
            ListNode* fast = head;  // Fast pointer to move 'n' steps ahead
    
            // Move fast pointer 'n' steps ahead
            for(int i = 0; i < n; i++) 
                fast = fast->next;
    
            // If fast reaches NULL, it means we need to remove the first node
            if(fast == NULL) 
                return head->next;
    
            // Move both pointers until fast reaches the last node
            while(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;  
            }
    
            // Skip the nth node from the end
            slow->next = slow->next->next;
    
            // Return the updated linked list
            return head;
        }
    };
    