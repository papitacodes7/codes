//https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x, TreeNode *l, TreeNode *r) {
        val = x;
        left = l;
        right = r;
    }
};

class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (!root) return INT_MAX;

        int ans = INT_MAX;

        if (root->left) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        if (prev) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        if (root->right) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};

int main() {
    /*
        Example BST
              4
            /   \
           2     6
          / \
         1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    cout << "Minimum Difference: " << obj.minDiffInBST(root);

    return 0;
}

//so basically hum jese arrays me minimum find krne ke liye.. like minimum of two numbers toh usme apan uske ek number aage and piche se - krke dekhte the kyyuki woh ans ussi me lie krega cz of sorted fashion.. so same here bhi krna he.. just hume inorder traversal krna he.. cz it's a bst so sorted hojyga fir uske baad like inorder traversal ko hi thoda modify krdenge toh apna kaam ho jyga.. so hume previous track krne ke liye ek previous bnana pdega toh pehle woh banynge and uske baad what we are gooing to do is ek answer variable bhi bnynge jo left and right traversal in inorder traversal me ans variable ko update krega.. if starting me previous nhi he toh hum apna first node hit kiye hein in left so hum prev me root value store krdenge.. and ans variable ko update krte chlenge just like inorder traversall.. for left and right.


//So basically the idea is that in a BST the inorder traversal always gives nodes in sorted order. And whenever numbers are sorted, the minimum difference will always lie between two adjacent elements, not somewhere far apart. Just like in arrays when we want the minimum difference we check arr[i] - arr[i-1] because the closest values will be neighbors in sorted order. So we do the same thing here: we perform an inorder traversal of the BST and keep track of the previous node using a prev pointer. When we visit a node, if prev already exists, we calculate root->val - prev->val and update our ans if it’s smaller. Then we update prev to the current node and continue the traversal for left and right. This way while doing the inorder traversal itself we keep updating the minimum difference and finally return it.
// Time Complexity: O(n) because we visit every node once.
// Space Complexity: O(h) due to recursion stack, where h is the height of the tree (worst case O(n) for skewed tree, O(log n) for balanced tree).

//https://youtu.be/WZmjRXF_Zi4?si=wPSNZGCSXHiBSobs refer this for dry run