#include <bits/stdc++.h>
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            leftToRight = !leftToRight;

            for (auto val : level) {
                result.push_back(val);
            }
        }

        return result;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> ans = obj.zigZagTraversal(root);

    cout << "ZigZag Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

//ZigZag traversal basically normal level order traversal hi hai, bas har level ka direction alternate karna hota hai. Sabse pehle ek `result` vector banaate hain jisme final answer store hoga. Agar root exist nahi karta toh directly empty result return kar dete hain. Phir ek `queue<Node*>` banaake root usme push kar dete hain, exactly BFS ki tarah. Ek boolean `leftToRight` ko initially `true` set karte hain kyunki first level left se right hi hota hai. Ab jab tak queue empty nahi hoti, har level ke liye pehle uska size nikaalte hain aur ek temporary vector banaate hain us size ka. Phir us level ke nodes process karte waqt agar direction left to right hai toh value ko normal index `i` pe daalte hain, aur agar right to left hai toh `size - 1 - i` index pe daalte hain taaki reverse order me fill ho jaaye. Isse hume alag se reverse karne ki zarurat nahi padti. Har level ke baad `leftToRight = !leftToRight` karke direction flip kar dete hain. Saare levels process hone ke baad result vector return kar dete hain. Time complexity O(N) hai kyunki har node ek baar visit hota hai, aur space complexity bhi O(N) hai queue aur level storage ki wajah se.
