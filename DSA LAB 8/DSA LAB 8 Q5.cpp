#include <iostream>
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;
    int includeRob;  
    int excludeRob; 
// Constructor 
    Node(int val) {
        value = val;
        left = right = nullptr;
        includeRob = excludeRob = -1; 
    }
};
class Tamia_004 {
public:
    Node* root;
    Tamia_004() : root(nullptr) {}
// Method to calculate the maximum amount of money
    int maxRobAmount(Node* node) { 
        return robberyHelper(node);
    }

private:
// Helper function to calculate the max value based on the choice of robbing or not robbing a node
    int robberyHelper(Node* node) { 
        if (!node) return 0;

    // If this node's result has already been calculated, use it
        if (node->includeRob != -1) {
            return node->includeRob; 
        }

    // Option 1: Rob this node, skip the immediate children
        int robCurrent = node->value;
        if (node->left) {
            robCurrent += robberyHelper(node->left->left) + robberyHelper(node->left->right);
        }
        if (node->right) {
            robCurrent += robberyHelper(node->right->left) + robberyHelper(node->right->right);
        }

    // Option 2: Do not rob this node, consider the immediate children
        int notRobCurrent = robberyHelper(node->left) + robberyHelper(node->right);

    // Choose the better option between robbing this node or not
        int result = max(robCurrent, notRobCurrent);
        
    // Store the result in the appropriate field
        node->includeRob = result; 
        return result;
    }
};

int main() {
    Tamia_004 T;
    T.root = new Node(30); 
    T.root->left = new Node(22);
    T.root->right = new Node(35);
    T.root->left->right = new Node(31);
    T.root->right->right = new Node(17);
    cout << "Maximum amount the thief can rob: " << T.maxRobAmount(T.root) << endl;
    return 0;
}
