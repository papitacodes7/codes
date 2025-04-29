/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

 Node * deleteAllOccurrences(Node* head, int k) {
    // Initialize a pointer to traverse the list
    Node * temp = head;

    // Traverse the entire doubly linked list
    while(temp != NULL) {
        // Check if the current node's data matches the target value
        if(temp->data == k) {

            // If the current node is the head node, move head to the next node
            if(temp == head) {
                head = temp->next;
            }

            // Store next and previous pointers for reconnection
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            // If the next node exists, update its prev pointer to skip the current node
            if(nextNode != NULL) {
                nextNode->prev = prevNode;
            }

            // If the previous node exists, update its next pointer to skip the current node
            if(prevNode != NULL) {
                prevNode->next = nextNode;
            }

            // Free the memory occupied by the current node
            delete temp;  // Use `delete` in C++ instead of `free`

            // Move to the next node
            temp = nextNode;
        } else {
            // If current node doesn't match k, move to the next node
            temp = temp->next;
        }
    }

    // Return the possibly updated head pointer
    return head;
}

/* * The function takes a pointer to the head of the list and an integer key as input.
* The function deletes all occurrences of a given key in a doubly linked list.
* It traverses the list, and for each node that matches the key, it updates the pointers of the adjacent nodes to bypass the current node.
 * The function handles the case where the node to be deleted is the head of the list*/