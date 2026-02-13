#include <iostream>
using namespace std;

// Structure of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int height(Node* root) {
        if (!root) return -1;  // height in terms of edges

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }
};

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

    Solution obj;
    cout << "Height of tree (in edges): " << obj.height(root) << endl;

    return 0;
}


//basically isme apan left part and right part me recursion kr rhe hein.. jo bhi bdha hoga usko return krdenge +1 krke.. that's it.. o(n) and o(n) me kaam hojyga.. 