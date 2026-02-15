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
    void postorder(TreeNode* root, vector<int> &ans){
        if(!root) return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
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
    vector<int> result = obj.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}


//Postorder ka rule hota hai:

// Left → Right → Root

// Matlab:

// Pehle left subtree ko completely process karo

// Phir right subtree ko completely process karo

// Sabse last me current node ko visit karo

// Is traversal me root sabse last me process hota hai.

// Ye traversal tab useful hota hai jab:

// Height calculate karni ho

// Diameter nikalna ho

// Tree delete karna ho

// Kyunki parent ka kaam tab tak complete nahi ho sakta jab tak children ka kaam complete na ho.

// Isliye postorder ka core idea hai:

// “Children finish first, then parent.”

