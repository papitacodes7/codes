/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        // diameter in terms of edges
        ans = max(ans, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        height(root);
        return ans;
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

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    cout << "Diameter (in edges): " 
         << obj.diameterOfBinaryTree(root) 
         << endl;

    return 0;
}

//this is 4) one.. just leetcode pe bhi krdiya..
//If the height function were defined to count the number of edges instead of nodes (by using a base case like if (!root) return -1;), then each recursive call would return the number of edges from the current node down to the deepest leaf. In that case, left and right would already represent edge counts, so when calculating the diameter through the current node, we would need to add +2 (one edge from the current node to the left child and one to the right child). Therefore, the diameter formula would become left + right + 2, since we must explicitly include the two connecting edges that join the left and right paths through the current node.

//The diameter of a binary tree is the length of the longest path between any two nodes, and this path may or may not pass through the root. At every node, the longest path can either lie entirely in the left subtree, entirely in the right subtree, or pass through the current node. Since we already know how to calculate height using recursion (by returning 1 + max(leftHeight, rightHeight)), we can use this same traversal to compute the diameter efficiently. While calculating the height of each node, we check the value leftHeight + rightHeight, which represents the longest path passing through that node, and update a variable to store the maximum value seen so far. This allows us to compute both height and diameter in a single traversal, giving an optimal time complexity of O(n). If we use left + right, the diameter is measured in terms of edges, and if we use left + right + 1, it is measured in terms of nodes.