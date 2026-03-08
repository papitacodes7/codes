#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
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
int minValue(Node* root) {
if (!root) return -1;


    while (root->left) {
        root = root->left;
    }

    return root->data;
}

};

int main() {
/*
20
/  
10    30
/  
5   15
/
2
*/

Node* root = new Node(20);
root->left = new Node(10);
root->right = new Node(30);
root->left->left = new Node(5);
root->left->right = new Node(15);
root->left->left->left = new Node(2);

Solution obj;

cout << "Minimum value in BST: " << obj.minValue(root);

return 0;


}


//The intuition comes directly from the Binary Search Tree property: for every node, all values in the left subtree are smaller and all values in the right subtree are larger. Because of this ordering, the smallest element must lie on the extreme left side of the tree. So instead of checking every node like in a normal binary tree, we can simply start at the root and keep moving to the left child until there is no further left node. The moment we reach a node whose left pointer is NULL, we know we have reached the leftmost node, which contains the minimum value in the BST. This makes the process efficient since we only traverse along the height of the tree instead of visiting all nodes.