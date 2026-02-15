#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);   
        ans.push_back(root->val);   
        inorder(root->right, ans);  
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
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
    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);   
        ans.push_back(root->val);   
        inorder(root->right, ans);  
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
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
    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}


//Inorder traversal ka matlab hai:

// Left subtree → Root → Right subtree

// Idea simple hai:

// Har node ke liye:

// Pehle uske left subtree ko completely traverse karo

// Phir current node ko visit karo (value store karo)

// Phir right subtree traverse karo

// Hum recursion use karte hain kyunki har subtree bhi ek chhota binary tree hi hota hai.
// Jab tak left child exist karta hai, hum left side me jaate rehte hain.
// Jab NULL milta hai, wapas aate hain, current node ko process karte hain,
// phir right side me move karte hain.

// Is tarah nodes exactly us order me visit hote hain jo Left → Root → Right follow karta hai.

//Agar tree Binary Search Tree (BST) hai,
// to inorder traversal hamesha sorted order deta hai.

// Kyun?

// Kyuki BST me:

// left < root < right


// Aur inorder bhi wahi sequence follow karta hai.

// ⏱ Complexity

// Time Complexity: O(n) → har node ek baar visit hota hai

// Space Complexity: O(h) → recursion stack (h = height of tree)