#include <bits/stdc++.h>
using namespace std;

/* A binary tree node */
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> diagonal(Node *root) 
    {
        vector<int> ans;

        // Null check
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) 
        {
            Node* curr = q.front();
            q.pop();

            while (curr) 
            {
                // Push left child for next diagonal
                if (curr->left)
                    q.push(curr->left);

                // Store current node
                ans.push_back(curr->data);

                // Move to right (same diagonal)
                curr = curr->right;
            }
        }

        return ans;
    }
};

// ----------- MAIN FUNCTION ------------
int main()
{
    /*
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \     /
         4   7   13
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution obj;
    vector<int> result = obj.diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}


// go right and left jo aaye queue me daalo etc. that's it

//Simple sa logic hai — root ko queue me daalo, fir jab bhi koi node nikale, usse right side me continuously move karte jao kyunki right wale same diagonal me hote hain. Aur jaise hi left child mile, usko queue me daal do kyunki wo next diagonal ka start hoga. Bas ye process repeat karo jab tak queue empty na ho jaye..


//The intuition behind this approach is to treat the tree as a series of sloping diagonals where each "right" move keeps you on the same path, and every "left" move starts a new one. We use Node* curr as a dynamic pointer that "slides" down the current diagonal by constantly jumping to the curr->right child. The reason we use the q.front() and q.pop() combo is to "check in" a node and then immediately "clear it out" of the queue once we've grabbed its address, ensuring we don't process the same starting point twice. Since every left child we encounter represents the start of a future diagonal, we push them into the queue to wait their turn. The shorthand while(curr) acts as a simple "is-there-a-node-here?" check; as soon as curr hits a NULL (the end of a diagonal), the loop breaks and the outer loop pulls the next starting node from the queue. This results in a Time Complexity of O(N) because every node is visited exactly once, and a Space Complexity of O(N) in the worst case to store the left children in the queue.