#include <bits/stdc++.h>
using namespace std;
class Node { 
public:
    int value;
    Node* left;
    Node* right;
// constructor
    Node(int val) { 
        value = val;
        left = right = nullptr;
    }
};
class Tamia_004 {
public:
    Node* root;
    Tamia_004() {
        root = nullptr;
    }

    void add(int n) {
        Node* newNode = new Node(n);
        if (root == nullptr) { 
            root = newNode;
            return;
        }
// BFS for level order insertion
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

// SYMMETRIC FUNCTION
    bool isMirror(Node* left, Node* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return (left->value == right->value) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
// EMPTY TREE IS SYMMETRIC    
    bool isSymmetric() {
        if (root == nullptr) return true; 
        return isMirror(root->left, root->right);
    }
};

int main() {
    Tamia_004 T;
    T.add(45);
    T.add(145);
    T.add(245);
    T.add(3);
    T.add(245);
    T.add(145);
    T.add(45);
    if (T.isSymmetric()) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }
    return 0;
}
