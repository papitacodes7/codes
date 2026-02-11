#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* A binary tree Node */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        
        vector<vector<int>> result;
        
        if (root == NULL)
            return result;
            
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                
                Node* temp = q.front();
                q.pop();
                
                level.push_back(temp->data);
                
                if (temp->left)
                    q.push(temp->left);
                    
                if (temp->right)
                    q.push(temp->right);
            }
            
            result.push_back(level);
        }
        
        return result;
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
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    // Print result
    for (auto level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


// Level Order Traversal uses the Breadth First Search (BFS) approach to traverse a binary tree level by level from left to right. We use a queue because it follows FIFO (First In First Out), which ensures that nodes are processed in the order they are discovered. First, we push the root node into the queue. Then, while the queue is not empty, we record the current queue size to determine how many nodes belong to the current level. We process exactly those many nodes by removing them from the queue, adding their values to a temporary level vector, and pushing their left and right children (if they exist) into the queue for future processing. This freezing of the queue size ensures proper level separation. Each node is visited exactly once, so the time complexity is O(N), and in the worst case the queue may store up to N nodes, giving a space complexity of O(N).