#include <iostream>
#include <stack>  
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

    void insert(int key) {
        root = insertRec(root, key);
    }

    void preorderTraversal() {
        if (root == nullptr) return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            cout << current->value << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
        cout << endl;
    }

    void postorderTraversal() {
        if (root == nullptr) return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->value << " ";
            s2.pop();
        }
        cout << endl;
    }

private:
    Node* insertRec(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->value)
            node->left = insertRec(node->left, key);
        else if (key > node->value)
            node->right = insertRec(node->right, key);

        return node;
    }
};

int main() {
    Tamia_004 bst;
    bst.insert(540);
    bst.insert(330);
    bst.insert(220);
    bst.insert(410);
    bst.insert(740);
    bst.insert(650);
    bst.insert(807);

    cout << "Preorder traversal of the tree: ";
    bst.preorderTraversal();
    cout << "Postorder traversal of the tree: ";
    bst.postorderTraversal();
    return 0;
}
