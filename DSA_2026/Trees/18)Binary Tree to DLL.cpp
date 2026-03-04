#include <iostream>
using namespace std;

// Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    // Helper function to perform the conversion
    void convert(Node* root, Node*& head, Node*& prev) {
        if (root == NULL) return;

        // Traverse Left
        convert(root->left, head, prev);

        // Process current node
        if (prev == NULL) {
            head = root; // First node found (leftmost)
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        // Traverse Right
        convert(root->right, head, prev);
    }

    Node* bToDLL(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;
        convert(root, head, prev);
        return head;
    }
};

// Utility function to print the DLL in both directions
void printList(Node* head) {
    Node* temp = head;
    Node* last = NULL;

    cout << "Forward Traversal:  ";
    while (temp != NULL) {
        cout << temp->data << " ";
        last = temp;
        temp = temp->right;
    }
    
    cout << "\nBackward Traversal: ";
    while (last != NULL) {
        cout << last->data << " ";
        last = last->left;
    }
    cout << endl;
}

int main() {
    /* Constructed binary tree is:
              10
             /  \
            12   15
           /  \  /
          25  30 36
    */
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Solution obj;
    Node* head = obj.bToDLL(root);

    // Print the resulting DLL
    printList(head);

    return 0;
}


//so basically like isme LNR use hua he that is inorder traversal and like wohi ki prev ka right set as root and root ka left set as prev if it's a node in between warna basically head banana pdega jo first node hoga..



//The intuition behind converting a Binary Tree to a Doubly Linked List lies in performing a standard Inorder Traversal (Left-Root-Right) to preserve the linear sequence of nodes. By maintaining a prev pointer that tracks the last visited node, we can dynamically reassign the tree's left and right pointers to act as previous and next links in a DLL. As we reach each node, we link it to the prev node and move the prev pointer forward, effectively "flattening" the tree structure into a linked chain without allocating extra nodes. The Time Complexity is O(N) because every node is visited exactly once, while the Space Complexity is O(H), where H is the height of the tree, representing the maximum depth of the recursion stack (which becomes O(N) in the case of a skewed tree).