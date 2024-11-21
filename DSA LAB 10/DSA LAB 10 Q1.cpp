#include <iostream>
using namespace std;
// Node class representing each node in the AVL tree
class Node {
public:
    int key;        // Key of the node
    Node* left;     // Left child
    Node* right;    // Right child
    int height;     // Height of the node for balancing

    // Constructor to initialize a new node
    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1; // New nodes are initialized with height 1
    }
};

// AVL tree class with insert, delete, and balance functions
class Tamia_004 {
private:
    Node* root; // Root of the AVL tree

    // Helper function to get the height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Helper function to calculate balance factor of a node
    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Updates the height of a node based on the heights of its children
    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    // Right rotation to balance nodes (used for Left-Left cases)
    Node* rotateRight(Node* y) {
        Node* x = y->left;    // x becomes new root
        Node* T2 = x->right;  // T2 is temporarily stored

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights after rotation
        updateHeight(y);
        updateHeight(x);

        // Return the new root
        return x;
    }

    // Left rotation to balance nodes (used for Right-Right cases)
    Node* rotateLeft(Node* x) {
        Node* y = x->right;   // y becomes new root
        Node* T2 = y->left;   // T2 is temporarily stored

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights after rotation
        updateHeight(x);
        updateHeight(y);

        // Return the new root
        return y;
    }

    // Balances the given node if it becomes unbalanced
    Node* balance(Node* node) {
        updateHeight(node);   // Update the node's height first
        int balance = balanceFactor(node);

        // Left heavy case
        if (balance > 1) {
            // Left-Right case
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left); // Left rotation on left child
            return rotateRight(node); // Right rotation on the current node
        }

        // Right heavy case
        if (balance < -1) {
            // Right-Left case
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right); // Right rotation on right child
            return rotateLeft(node); // Left rotation on the current node
        }

        return node; // Node is balanced, no rotation needed
    }

    // Finds the node with the minimum key in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Inserts a new key into the AVL tree and balances it
    Node* insert(Node* node, int key) {
        // Perform standard BST insertion
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // Duplicate keys are not allowed

        // Balance the node after insertion
        return balance(node);
    }

    // Deletes a node with the given key and balances the AVL tree
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr)
            return node;

        // Perform standard BST delete
        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            // Node with only one child or no child
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp = node->left ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else { // One child case
                    *node = *temp; // Copy the contents of the non-empty child
                }
                delete temp;
            } else {
                // Node with two children: get the inorder successor
                Node* temp = minValueNode(node->right);
                node->key = temp->key; // Copy the inorder successor's key
                node->right = deleteNode(node->right, temp->key); // Delete successor
            }
        }

        if (node == nullptr)
            return node;

        // Balance the node after deletion
        return balance(node);
    }

    // In-order traversal to print the AVL tree nodes
    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);             // Visit left subtree
        cout << node->key << " ";        // Print node's key
        inOrder(node->right);            // Visit right subtree
    }

public:
    // Constructor to initialize the AVL tree
    Tamia_004() { 
        root = nullptr;
    }

    // Public method to insert a key in the AVL tree
    void insert(int key) {
        root = insert(root, key);
    }

    // Public method to delete a key from the AVL tree
    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    // Public method to perform in-order traversal
    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

// Main function to demonstrate AVL tree operations
int main() {
    Tamia_004 tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20); // Duplicate insertion, ignored
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order traversal before deletion: ";
    tree.inOrder();

    // Delete a node and show in-order traversal again
    tree.deleteKey(20);
    cout << "In-order traversal after deleting 20: ";
    tree.inOrder();

    return 0;
}
