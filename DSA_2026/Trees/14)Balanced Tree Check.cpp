#include <iostream>
#include <algorithm>
using namespace std;

// Definition of Node
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
    bool isBalanced(Node* root) {
        return height(root) != -1;
    }
    
    int height(Node* root) {
        if(!root) return 0;
        
        int leftHeight = height(root->left);
        if(leftHeight == -1) return -1;
        
        int rightHeight = height(root->right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1;
        
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    /*
            1
           / \
          2   3
         /
        4
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution obj;
    
    if(obj.isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is Not Balanced" << endl;

    return 0;
}



//jab bhi >1 height reach kregi that means ki balanced nhi he return -1.. jab bhi -1 aaya that means uske pehle waali node -1 return kregi.. etc. it's a simple code but make sure to see that dry run it's really usefull..


// make sure to see this dry run again to understand the problem properly.. i have seen it once and acche se smhj aagya tha but next time whenever you do this problem make sure to see this dry run.. the code is simple enought but ye dry run dekh lena.. (from past param to future param..) 
//IMPORTANT
//https://youtu.be/Yt50Jfbd8Po?si=WfJJnQyKAElaQQNE&t=540





//Simple sa logic hai. Balanced binary tree ka matlab hota hai ki har node pe left aur right subtree ki height ka difference 1 se zyada nahi hona chahiye. Toh maine ek hi function height() me dono kaam kar diye — height calculate karna bhi aur balance check karna bhi. Agar subtree properly balanced hai toh function normal height return karega, lekin agar kahin bhi height difference 1 se zyada mil gaya toh main -1 return kar deta hoon, jo signal karta hai ki ye subtree unbalanced hai. Aur jaise hi kisi child se -1 aata hai, main turant parent ko bhi -1 return kar deta hoon, kyunki agar neeche imbalance hai toh upar wala bhi automatically unbalanced hi hoga. Finally, isBalanced() sirf ye check karta hai ki height -1 hai ya nahi — agar -1 nahi hai toh tree balanced hai, warna nahi. Ye approach efficient hai kyunki har node sirf ek baar visit hoti hai aur unnecessary height recalculation nahi hota.