/**
 * Definition of doubly linked list:
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
 */

 Node* removeDuplicates(Node* head) {
    Node* temp = head;

    // Traverse the entire list
    while (temp != NULL && temp->next != NULL) {
        Node* nextNode = temp->next;

        // Skip and delete all nodes with duplicate values
        while (nextNode != NULL && nextNode->data == temp->data) {
            Node* duplicate = nextNode;        // Store the duplicate node
            nextNode = nextNode->next;         // Move to next node
            delete duplicate;                  // Free memory of duplicate node
        }

        // Link the current node to the next unique node (if any)
        temp->next = nextNode;

        // If next unique node exists, update its prev pointer
        if (nextNode != NULL)
            nextNode->prev = temp;

        // Move to the next node
        temp = temp->next;
    }

    return head;  // Return updated head
}
