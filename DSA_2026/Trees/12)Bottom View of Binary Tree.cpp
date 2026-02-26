#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int,int> mpp;   // horizontal distance -> node value
        queue<pair<Node*,int>> q;  // node and its horizontal distance
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            // overwrite every time (bottom-most survives)
            mpp[line] = node->data;
            
            if(node->left)
                q.push({node->left, line - 1});
                
            if(node->right)
                q.push({node->right, line + 1});
        }
        
        for(auto it : mpp)
            ans.push_back(it.second);
            
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5    6
               /
              7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    Solution obj;
    vector<int> result = obj.bottomView(root);

    cout << "Bottom View: ";
    for(int val : result)
        cout << val << " ";
    
    return 0;
}
//so this is basically top view but yk without that if condition where we check ki mapp me already woh line aachuki he yaa nhi..

// The core idea of the bottom view of a binary tree is to observe the tree vertically using horizontal distance (HD), where the root has HD 0, the left child has HD −1, and the right child has HD +1. We perform a level order traversal (BFS) so that nodes are processed level by level from top to bottom. For each node, we store its value in a map based on its horizontal distance. The key difference from the top view is that in top view we insert a node into the map **only if that horizontal distance is not already present** (using a condition like `if(mpp.find(line)==mpp.end())`), because we want the first visible node. However, in bottom view, there is **no such if-condition** — we always overwrite `mpp[line] = node->data`, because we want the last (deepest) node at that vertical line. Since BFS processes upper levels first and lower levels later, deeper nodes automatically replace earlier ones. In overlapping situations at the same horizontal distance and same level, we push the left child first and the right child after, so the right child is processed later and overwrites the left one, ensuring correct bottom-most visibility. Finally, we collect the values from the map in sorted order of horizontal distance. The time complexity is **O(N log N)** due to map insertions, and the space complexity is **O(N)** for storing nodes in the queue and map.
