#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition of Node
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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        map<int, int> mpp;  // HD -> node value
        queue<pair<Node*, int>> q;  // node + horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();

            Node* node = frontNode.first;
            int hd = frontNode.second;

            // Insert only first node at this horizontal distance
            if (mpp.find(hd) == mpp.end()) {
                mpp[hd] = node->data;
            }

            if (node->left != nullptr) {
                q.push({node->left, hd - 1});
            }

            if (node->right != nullptr) {
                q.push({node->right, hd + 1});
            }
        }

        for (auto &it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \
            4

       Top View should be: 2 1 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "Top View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}



//basically we need a queue jisme aayga Node and level.. and map me aayga level and node... now woh number line wala concept lagaake.. mapp me chizein daalni he..

//Intuition yeh hai ki **top view** ka matlab hota hai har vertical line (horizontal distance) par jo sabse pehla node upar se dikhe, sirf wahi lena. Isliye hum level order traversal (BFS) use karte hain, kyunki BFS hamesha upar wale nodes ko pehle visit karta hai. Hum ek `map<int,int>` use karte hain jisme key horizontal distance (line) hai aur value node ka data. Root ka line 0 hota hai, left child ka line -1, right child ka +1. Jab bhi queue se node nikalte hain, agar us line ke liye map me pehle se koi entry nahi hai, tabhi us node ka data store karte hain — kyunki woh us vertical line ka sabse pehla (topmost) node hoga. Agar already entry hai toh ignore kar dete hain, kyunki neeche wale nodes top view me nahi aayenge. End me map sorted hota hai line ke according (left se right), isliye uske values ko ans me push karke final top view mil jata hai.
