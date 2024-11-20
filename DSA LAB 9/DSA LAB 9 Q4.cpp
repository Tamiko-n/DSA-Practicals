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

    int sumOfNodes(Node* root) {
        if (root == nullptr) return 0; 

        return root->value + sumOfNodes(root->left) + sumOfNodes(root->right);
    }
};

int main() {
    Tamia_004 T;
    T.root = T.insert(T.root, 10);
    T.insert(T.root, 5);
    T.insert(T.root, 15);
    T.insert(T.root, 3);
    T.insert(T.root, 7);
    int sum = T.sumOfNodes(T.root);
    cout << "Sum of all nodes: " << sum << endl;
    return 0;
}
