#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            ans.push_back(temp->data);

            // Push right first, then left
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \  /
        4  5 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution obj;
    vector<int> result = obj.reverseLevelOrder(root);

    cout << "Reverse Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

/// basically like jese apan ne using queue and stack implement kiya tha level order traversall wese hi krna he.. what we can do is reverse the ans vector jisme hum store krenge overall answer in the end.. kyuki apan right side pehle insert kr reh hein.. toh ulta ho jyga.. toh during the traversal right se left store hoga and in the end reverse hojyga.. wanted to write more but the net's prb oover its 12/2/26 and 11:55.. have to leave..





// The intuition behind reverse level order traversal is simple. Normally in level order traversal (BFS), we use a queue and visit nodes level by level from top to bottom, and we insert the left child first and then the right child. But here our goal is different — we want the answer from bottom to top, while still keeping the left to right order correct in every level.
// So starting se hi we decide that right side ki child pehle insert karni hai, fir left side ki. We push the right child first and then the left child into the queue. The reason for this is that at the end we are going to reverse the final result vector. If we inserted left first (like normal BFS), then after reversing, the left-to-right order of nodes would get disturbed. But because we insert right first, the order gets adjusted in such a way that after reversing, everything becomes correct — bottom level comes first and each level still stays left to right
// So basically, we do a normal BFS with one small change (right first, left later), store all values, and finally reverse the vector to get the reverse level order traversal efficiently in O(N) time.