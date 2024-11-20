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
    int minDiff;
    Node* prev;

    Tamia_004() {
        root = prev = nullptr;
        minDiff = INT_MAX;
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

    void inorderTraversal(Node* root) {
        if (root == nullptr) return;

        inorderTraversal(root->left);

        if (prev != nullptr) {
            minDiff = min(minDiff, root->value - prev->value);
        }
        prev = root;

        inorderTraversal(root->right);
    }

    int MinimumDifference(Node* root) {
        inorderTraversal(root);
        return minDiff;
    }
};

int main() {
    Tamia_004 tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 7);

    int md = tree.MinimumDifference(tree.root);
    cout << "Minimum difference between two nodes is: " << md << endl;
    return 0;
}
