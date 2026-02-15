#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);     // Visit root first
        preorder(root->left, ans);   // Then left
        preorder(root->right, ans);  // Then right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
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
    vector<int> result = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}


//Preorder traversal ka rule hota hai:

// Root → Left → Right

// Matlab:

// Sabse pehle current node ko visit karo.

// Phir uske left subtree me jao.

// Phir uske right subtree me jao.

// Is traversal me root sabse pehle process hota hai.
// Isliye agar tree ko copy karna ho ya serialize karna ho, preorder useful hota hai.

// Recursion ka idea yeh hai ki har subtree bhi ek chhota binary tree hi hai,
// to hum same function ko recursively left aur right dono par apply kar dete hain.