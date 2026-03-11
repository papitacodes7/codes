#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class BSTIterator {
public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();

        if(node->right){
            storeLeftNodes(node->right);
        }

        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

int main() {

    // Creating BST
    /*
            7
           / \
          3   15
             /  \
            9   20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    while(it.hasNext()){
        cout << it.next() << " ";
    }

    return 0;
}


//Is question me hume next() aur hasNext() functions implement karne hote hain taaki hum BST ko inorder traversal order me iterate kar sakein, kyunki BST ka inorder traversal sorted order deta hai. Iske liye hum stack use karte hain kyunki stack LIFO follow karta hai aur hume traversal ko step-by-step control karne me help milti hai instead of ek baar me pura traversal karne ke. Constructor me hum root se start karke uske saare left nodes stack me push kar dete hain, kyunki inorder traversal me sabse pehle leftmost node visit hota hai. Jab bhi next() call hota hai, hum stack ka top node pop karte hain jo next smallest element hota hai, aur agar us node ka right subtree exist karta hai toh uske right child se start karke uska poora left chain stack me push kar dete hain taaki inorder order maintain rahe. hasNext() function bas ye check karta hai ki stack empty hai ya nahi; agar stack me nodes bache hue hain toh next element available hai.
//https://youtu.be/dS1bKglre3A?si=eMsrpXnj9ESy-wXb