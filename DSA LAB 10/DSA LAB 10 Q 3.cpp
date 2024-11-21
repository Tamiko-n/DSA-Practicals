#include <iostream>
using namespace std;
class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) {
        value = val;
        next = nullptr;
    }
};
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
    ListNode* head;  
    // Function to find the middle of the linked list using slow and fast pointers
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        // Move slow by one step and fast by two steps to find the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // Disconnect the left half of the list from the middle
        if (prev != nullptr) {
            prev->next = nullptr;
        }
        return slow;
    }
    // Function to convert the sorted linked list to a height-balanced BST
    Node* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        // Find the middle node (this becomes the root)
        ListNode* mid = findMiddle(head);
        // Create the root node for the BST
        Node* root = new Node(mid->value);
        // Base case: if the list has only one node, return the node as the root
        if (head == mid) return root;
        // Recursively construct the left and right subtrees
        root->left = sortedListToBST(head);  // Left half
        root->right = sortedListToBST(mid->next);  // Right half
        return root;
    }
    // Helper function to print the inorder traversal of the BST
    void inorderTraversal(Node* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }

public:
    Tamia_004(ListNode* head) {
        this->head = head; 
    }
    // Function to convert the linked list to BST and print its inorder traversal
    void convertAndDisplayBST() {
        Node* root = sortedListToBST(head);
        cout << "Inorder Traversal of the BST: ";
        inorderTraversal(root);
        cout << endl;
    }
};
int main() {
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    Tamia_004 T(head);
    T.convertAndDisplayBST();  
    return 0;
}
