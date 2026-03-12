#include <iostream>
#include <vector>
using namespace std;

/* BST Node */
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    Node* rightMostInLeft(Node* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }

    Node* leftMostInRight(Node* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* curr = root;
        Node* pred = NULL;
        Node* succ = NULL;

        while(curr){

            if(key > curr->data){
                pred = curr;
                curr = curr->right;
            }

            else if(key < curr->data){
                succ = curr;
                curr = curr->left;
            }

            else{

                if(curr->left){
                    pred = rightMostInLeft(curr->left);
                }

                if(curr->right){
                    succ = leftMostInRight(curr->right);
                }

                break;
            }
        }

        return {pred, succ};
    }
};

/* Function to insert nodes in BST */
Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int main(){

    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 50;

    Solution obj;
    vector<Node*> ans = obj.findPreSuc(root, key);

    if(ans[0])
        cout << "Predecessor: " << ans[0]->data << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if(ans[1])
        cout << "Successor: " << ans[1]->data << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}

//basically intu ye he ki key denge usse find krke uska pred and succ batana he.. the thing is we compare key to root's data while going left or right tb woh root ki val can be pred and succ.. and also let's say key doesn't exist so basically tb bhi we have to find pred and succ.. that can be taken care of and also if key is found then pred is right most of the left and succ is leftmost of the right..



//In a Binary Search Tree, values on the left are smaller and values on the right are larger.
// While searching for the key:
// If key > curr->data, the current node could be the predecessor, so we store it and move right.
// If key < curr->data, the current node could be the successor, so we store it and move left.
// If we find the key:
// The predecessor is the rightmost node in the left subtree.
// The successor is the leftmost node in the right subtree.
// This works because BST keeps elements in sorted order.
// Time Complexity: O(h)
// Space Complexity: O(1)
// (h = height of the tree)



//Basically the problem is to find the predecessor and successor of a given key in a BST. We traverse the BST while comparing the key with the current node's value. If the key is greater than the current node, then that node can be a possible predecessor, so we store it and move to the right subtree. If the key is smaller, then that node can be a possible successor, so we store it and move to the left subtree. This way even if the key does not exist in the BST, we still get the correct predecessor and successor during traversal. If we find the key, then the predecessor will be the rightmost node of the left subtree and the successor will be the leftmost node of the right subtree, because those are the closest smaller and greater values respectively in a BST.