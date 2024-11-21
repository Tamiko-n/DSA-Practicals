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
    Node* root;
    Node* sortedBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        Node* node = new Node(nums[mid]);
        node->left = sortedBST(nums, left, mid - 1);
        node->right = sortedBST(nums, mid + 1, right);

        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }
public:
    Tamia_004(){
		root = nullptr; 
	}
    // Public method to initialize the BST from sorted array
    void FromSortedArray(vector<int>& nums) {
        root = sortedBST(nums, 0, nums.size() - 1);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};
int main() {
    Tamia_004 T;
    vector<int> nums = {-10, -3, 0, 5, 9};
    T.FromSortedArray(nums);
    cout << "Inorder Traversal of the BST: ";
    T.display();
    return 0;
}
