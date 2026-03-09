#include <iostream>
#include <vector>
using namespace std;

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

    void inorder(Node* root, vector<int>& arr){
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> merge(Node *root1, Node *root2) {

        vector<int> arr1, arr2;

        inorder(root1, arr1);
        inorder(root2, arr2);

        vector<int> ans;

        int i = 0, j = 0;

        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while(i < arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }

        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }

        return ans;
    }
};

int main() {

    // BST 1
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    // BST 2
    Node* root2 = new Node(1);
    root2->left = new Node(0);
    root2->right = new Node(3);

    Solution obj;

    vector<int> result = obj.merge(root1, root2);

    cout << "Merged BST elements: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}

// pehle inorder traversal nikaalo dono ka fir merge krdo ek array me and return krdo.. that's it.

//First perform inorder traversal on both BSTs because inorder of a BST always gives elements in sorted order. This will give us two sorted arrays. Then merge these two sorted arrays using the two-pointer technique (like in merge sort) into one array and return the result.


//Since inorder traversal of a BST always produces a sorted sequence, we first perform inorder traversal on both trees to get two sorted arrays. Once we have these arrays, the problem reduces to merging two sorted arrays. We use the same technique as the merge step in merge sort, comparing elements from both arrays and inserting the smaller one into the result until all elements are merged.