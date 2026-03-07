#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool search(Node* root, int key) {
        while(root && root->data != key){
            root = key < root->data ? root->left : root->right;
        }

        return root;
    }
};

int main() {

    /*
            10
           /  \
          5    15
         / \     \
        2   7     20
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    Solution obj;

    int key = 7;

    if(obj.search(root, key))
        cout << "Key Found\n";
    else
        cout << "Key Not Found\n";

    return 0;
}


// basically left < node < right so binary search jesa kuch krna chahiiye but instead of making some mid or something which is not possible here we can just use a while loop to traverse nodes and inside that while loop we can update that node whether left or right.. after that we can return that root..

//In a Binary Search Tree (BST), the property is **left < node < right**. Because of this ordering, we can search for a key in a way similar to **Binary Search**. However, unlike arrays, we cannot calculate a middle index since the data is stored as nodes connected by pointers. Instead, we start from the **root** and use a loop to traverse the tree. At each step, we compare the key with the current node's value. If the key is smaller, we move to the **left child**; if it is larger, we move to the **right child**. We continue updating the current node in this way until we either find the key or reach `NULL`. If the node becomes `NULL`, the key does not exist in the tree; otherwise, it is found.



//A Binary Search Tree (BST) stores elements in an ordered way where all values in the left subtree are smaller than the node and all values in the right subtree are greater. Because of this property, we don't need to search the entire tree. We start at the root and compare the key with the current node's value. If the key is equal, we have found it. If the key is smaller, we move to the left child because smaller values exist there. If the key is greater, we move to the right child. We keep repeating this process until we either find the key or reach a NULL node, which means the key is not present in the tree. This approach is efficient because at every step we discard half of the remaining tree, similar to binary search.

