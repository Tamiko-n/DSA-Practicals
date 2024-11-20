#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int x) {
        value = x;
        left = right = nullptr;
    }
};

class Tamia_004 {
public:
    Node* root;

    Tamia_004() {
        root = nullptr;
    }

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->value) {
            root->left = insert(root->left, value);
        } else if (value > root->value) {
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node* lca(Node* root, Node* p, Node* q) {
        if (root == nullptr) return nullptr;

        if (p->value < root->value && q->value < root->value) {
            return lca(root->left, p, q);
        }
        if (p->value > root->value && q->value > root->value) {
            return lca(root->right, p, q);
        }
        return root;
    }
};

int main() {
    Tamia_004 tree;
    tree.root = tree.insert(tree.root, 44);
    tree.insert(tree.root, 29);
    tree.insert(tree.root, 65);
    tree.insert(tree.root, 23);
    tree.insert(tree.root, 34);

    Node* p = tree.root->left;       
    Node* q = tree.root->right;      

    Node* lca = tree.lca(tree.root, p, q);
    if (lca) {
        cout << "Least Common Ancestor of " << p->value << " and " << q->value << " is: " << lca->value << endl;
    } else {
        cout << "Least Common Ancestor not found." << endl;
    }

    return 0;
}
