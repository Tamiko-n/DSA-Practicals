#include <iostream>
#include <vector>
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
    // Helper function to convert sorted array to a height-balanced BST
    Node* sortedArrayToBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        // Find the middle element
        int mid = left + (right - left) / 2;
        Node* node = new Node(nums[mid]);
        // Recursively build the left and right subtrees
        node->left = sortedArrayToBST(nums, left, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
    // Helper function for inorder traversal of the BST
    void inorderTraversal(Node* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }

public:
    // Function to convert the array to BST and print inorder traversal
    void convertAndDisplayBST(const vector<int>& nums) {
        Node* root = sortedArrayToBST(nums, 0, nums.size() - 1);
        cout << "Inorder Traversal of the BST: ";
        inorderTraversal(root);
        cout << endl;
    }
};
int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Tamia_004 T;
    T.convertAndDisplayBST(nums);  
    return 0;
}
