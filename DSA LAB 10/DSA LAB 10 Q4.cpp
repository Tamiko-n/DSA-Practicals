#include <iostream>
using namespace std;
class Node {
public:
    int value;        
    Node* left;        
    Node* right;       
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};
class Tamia_004 {
private:
    Node* root;  
    // Helper function to calculate the height of a node
    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
public:
    Tamia_004() {
        root = nullptr;
    }
    void setRoot(Node* node) {
        root = node;
    }
    int diameter(Node* node) {
        if (node == nullptr) return 0;

        // Get the height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Get the diameter of left and right subtrees
        int leftDiameter = diameter(node->left);
        int rightDiameter = diameter(node->right);

        // Return the maximum of the following:
        // 1. Diameter of left subtree
        // 2. Diameter of right subtree
        // 3. Height of left subtree + height of right subtree + 1
        return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    }
};
int main() {
    Tamia_004 T;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // Setting root in Tamia_004 object
    T.setRoot(root);
    cout << "Diameter of the BST is: " << T.diameter(root) << endl;
    return 0;
}
