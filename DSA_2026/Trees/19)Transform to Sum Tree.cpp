#include <iostream>
using namespace std;

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

    int solve(Node* node) {
        if (node == NULL)
            return 0;

        int left = solve(node->left);
        int right = solve(node->right);

        int original = node->data;

        node->data = left + right;

        return original + left + right;
    }

    void toSumTree(Node* node) {
        solve(node);
    }
};

// inorder traversal to check result
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
            10
           /  \
         20    30
        /  \
       40  50
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    Solution obj;
    obj.toSumTree(root);

    cout << "Inorder traversal of Sum Tree:\n";
    inorder(root);

    return 0;
}

//The idea is to convert every node of the tree so that it stores the sum of values of its left and right subtree from the original tree. To achieve this, we use postorder traversal (Left → Right → Node) because a node can only calculate its subtree sums after its children are processed.

// At each node, we recursively compute the sum of the left subtree and sum of the right subtree. Before updating the node, we store its original value. Then we replace the node’s value with leftSum + rightSum, which is exactly what the Sum Tree requires. Finally, we return leftSum + rightSum + originalValue to the parent so that the parent node can correctly compute its own subtree sum.

// Leaf nodes automatically become 0 because both their left and right subtree sums are 0.

// Time Complexity: O(N) (each node visited once)
// Space Complexity: O(H) recursion stack, where H is tree height.




// didn't did anything today on 6/2/26 xd