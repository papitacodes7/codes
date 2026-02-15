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
    void mirror(Node* root) {
        if (!root) return;

        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
};

// Inorder traversal to check result
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder before mirror: ";
    inorder(root);
    cout << endl;

    Solution obj;
    obj.mirror(root);

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}

// mirror matlb swap so left and right swap krlo sarr.. post order ya pre order kuch bhi chlega..

//Mirror ka simple sa matlab hai ki har node par uske left aur right child ko swap kar dena. Kyunki binary tree ke har subtree ko bhi ek independent chhota tree maan sakte hain, hum isi logic ko recursively apply kar dete hain. Har node par jaakar uske left aur right subtrees ko process karte hain aur phir unke pointers swap kar dete hain. Is problem mein swapping sirf pointers ka exchange hai, humein children se koi value calculate karke use nahi karni hoti, isliye preorder ya postorder dono traversal approach se solution sahi kaam karega. Har node ek hi baar visit hota hai, isliye time complexity O(n) hoti hai aur recursion stack ki wajah se space complexity O(h) hoti hai, jahan h tree ki height hai.


//We recursively mirror the left and right subtrees, and then swap the left and right child of the current node. This ensures that the entire tree is converted into its mirror image in O(n) time using postorder traversal.


//The idea is simple:


// At every node, we just need to swap its left and right child.

// But since a binary tree is made of smaller subtrees, we apply the same idea recursively.

// So for every node:

// First, we go to the left subtree and mirror it.

// Then, we go to the right subtree and mirror it.

// After both subtrees are processed, we swap the left and right pointers of the current node.

// This way, the smallest subtrees (leaf nodes) are handled first, and then the changes move upward toward the root.

// Because we process the children before swapping the current node, this follows postorder traversal (Left → Right → Root).

// Each node is visited exactly once, so:

// Time Complexity: O(n)

// Space Complexity: O(h), where h is height of the tree (recursion stack)