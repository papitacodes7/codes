/*
// Definition for a Node.
class Node {
public:
    int val;           // The value of the node
    Node* next;        // Pointer to the next node
    Node* random;      // Pointer to a random node in the list (can be NULL)
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
    
    // Step 1: Insert a copy of each node right after the original node in the list.
    void insertCopyInBetween(Node* head){
        Node* temp = head;
    
        // Traverse the original list
        while(temp != NULL){
            Node* nextElement = temp->next;    // Store the next node
    
            // Create a copy of the current node
            Node* copy = new Node(temp->val);
    
            // Insert the copy right after the original node
            copy->next = nextElement;
            temp->next = copy;
    
            // Move to the next original node (skipping the copy we just inserted)
            temp = nextElement;
        }
    }
    
    // Step 2: Assign the correct random pointers to the copied nodes
    void connectRandomPointers(Node* head){
        Node* temp = head;
    
        // Traverse the list again (original + copy interleaved)
        while(temp != NULL){
            Node* copyNode = temp->next;  // The copied node is just after the original
    
            // If the original node had a random pointer
            if(temp->random){
                // Set the copy's random to the copied version of temp->random
                copyNode->random = temp->random->next;
            }
            else{
                // If original random was NULL, keep copy's random also NULL
                copyNode->random = nullptr;
            }
    
            // Move to the next original node (skipping the copy node)
            temp = temp->next->next;
        }
    }
    
    // Step 3: Separate the original and copied nodes to form the deep copied list
    Node* getDeepCopyList(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);  // Dummy node to help build the result list
        Node* res = dummyNode;
    
        // Traverse the interleaved list
        while(temp != NULL){
            res->next = temp->next;          // Add the copy node to the result
            res = res->next;                 // Move the result pointer forward
    
            temp->next = temp->next->next;   // Restore the original list's next pointer
            temp = temp->next;               // Move to the next original node
        }
    
        return dummyNode->next;  // Return the head of the deep copied list
    }
    
    // Main function that puts all steps together
    Node* copyRandomList(Node* head) {
        // If the list is empty, just return NULL
        if (head == NULL) return NULL;
    
        // Step 1: Insert copies of each node
        insertCopyInBetween(head);
    
        // Step 2: Set correct random pointers for each copied node
        connectRandomPointers(head);
    
        // Step 3: Separate out the copied list and restore the original
        return getDeepCopyList(head);
    }
    };
    