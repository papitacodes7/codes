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
    
        // Helper function to return the k-th node (1-indexed) in the list
        ListNode* findNthNode(ListNode* temp, int k){
            int cnt = 1;  // Counter to track current node position
            while(temp != NULL){
                if(cnt == k) return temp;  // If we've reached the k-th node, return it
                cnt++;
                temp = temp->next;
            }
            return temp;  // In case k is out of bounds, return NULL
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            // Edge case: if list is empty or no rotation needed
            if(head == NULL || k == 0) return head;
    
            // Step 1: Find length of the linked list and the tail node
            ListNode* tail = head;
            int len = 1;  // Initialize length to 1 (we already have head)
            while(tail->next != NULL){
                tail = tail->next;
                len++;  // Count each node
            }
    
            // Step 2: Optimize k in case it's greater than length
            if (k % len == 0) return head;  // Rotation doesn't change the list
            k = k % len;
    
            // Step 3: Make the list circular by connecting tail to head
            tail->next = head;
    
            // Step 4: Find new last node after rotation
            // If we're rotating right by k, the new last node is at position (len - k)
            ListNode* newLastnode = findNthNode(head, len - k);
    
            // Step 5: Set new head to be the node after the new last node
            head = newLastnode->next;
    
            // Step 6: Break the loop to restore proper list structure
            newLastnode->next = NULL;
    
            return head;  // Return the new head of rotated list
        }
    };
    