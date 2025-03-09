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
        ListNode* oddEvenList(ListNode* head) {
            // If the list is empty or has only one node, return as is
            if (head == NULL || head->next == NULL) return head;
    
            // Initialize pointers for odd and even lists
            ListNode* odd = head;              // Points to the first odd-indexed node
            ListNode* even = head->next;       // Points to the first even-indexed node
            ListNode* evenHead = head->next;   // Store the head of even-indexed nodes
    
            // Rearranging nodes to separate odd and even indexed elements
            while (even != NULL && even->next != NULL) {
                odd->next = odd->next->next;   // Connect current odd node to the next odd node
                even->next = even->next->next; // Connect current even node to the next even node
    
                odd = odd->next;  // Move to the next odd node
                even = even->next; // Move to the next even node
            }
    
            // Connect the last odd-indexed node to the first even-indexed node
            odd->next = evenHead;
    
            // Return the updated linked list with odd nodes followed by even nodes
            return head;
        }
    };
    