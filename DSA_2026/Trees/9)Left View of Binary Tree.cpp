#include <iostream>
#include <vector>
using namespace std;

// Structure for Tree Node
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

    void solve(Node* root, vector<int>& ans, int level) {
        if (!root) return;

        // First time visiting this level
        if (ans.size() == level) {
            ans.push_back(root->data);
        }

        // Go left first
        solve(root->left, ans, level + 1);
        solve(root->right, ans, level + 1);
    }

    vector<int> leftView(Node* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> result = obj.leftView(root);

    cout << "Left View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}


//The left view of a binary tree consists of the first node visible at each level when observed from the left side. To achieve this using recursion, we perform a modified DFS traversal in Root → Left → Right order while tracking the current depth (level). We maintain a result vector that stores one node per level. Whenever we reach a node where level == ans.size(), it means we are visiting that level for the first time, so we push that node into the result. Since we traverse the left subtree before the right subtree, the first node encountered at each level is guaranteed to be the leftmost node. The time complexity is O(N) because each node is visited exactly once, and the space complexity is O(H) due to the recursion stack, where H is the height of the tree (worst case O(N) for skewed tree, O(log N) for balanced tree).