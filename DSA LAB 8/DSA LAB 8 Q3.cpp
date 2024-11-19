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
// Function to calculate height
    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

// Function to check if the tree is height-balanced
    bool isBalanced(Node* node) {
        if (node == nullptr) return true;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
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
    if (T.isBalanced(T.root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}
