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

    bool searchNode(int n) {
        return find(root, n);
    }

    void traverse(string order) { 
        if (order == "inorder")
            doInorder(root);
        else if (order == "preorder")
            doPreorder(root);
        else if (order == "postorder")
            doPostorder(root);
        cout << endl;
    }

private:
// inorder traversal
    void doInorder(Node* node) { 
        if (node == nullptr) return;
        doInorder(node->left);
        cout << node->value << " ";
        doInorder(node->right);
    }
// preorder traversal
    void doPreorder(Node* node) { 
        if (node == nullptr) return;
        cout << node->value << " ";
        doPreorder(node->left);
        doPreorder(node->right);
    }
// postorder traversal
    void doPostorder(Node* node) { 
        if (node == nullptr) return;
        doPostorder(node->left);
        doPostorder(node->right);
        cout << node->value << " ";
    }
// search function
    bool find(Node* node, int val) { 
        if (node == nullptr) return false;
        if (node->value == val) return true;
        return find(node->left, val) || find(node->right, val);
    }
};

int main() {
    Tamia_004 T;
	int n = 67;
    T.add(60);
    T.add(277);
    T.add(42);
    T.add(28);
    T.add(29);
    T.add(55);
    T.add(98);

    cout << "Inorder Traversal: ";
    T.traverse("inorder");

    cout << "Preorder Traversal: ";
    T.traverse("preorder");

    cout << "Postorder Traversal: ";
    T.traverse("postorder");

    if (T.searchNode(n)) {
        cout << "Node with value " << n << " found." << endl;
    } else {
        cout << "Node with value " << n << " not found." << endl;
    }
    return 0;
}
