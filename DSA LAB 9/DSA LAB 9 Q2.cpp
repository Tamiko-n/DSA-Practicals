#include <iostream>
using namespace std;
class EmployeeNode {
public:
    int id;
    string name;
    string dept;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(int ID, const string& n, const string& department){
    id = ID;
    name = n;
    dept = department;
    left = right = nullptr;
    }
};

class Tamia_004 {
private:
    EmployeeNode* root;

public:
      Tamia_004 (){
    root = nullptr;
}

    void insert(int id, const string& name, const string& dept) {
        EmployeeNode** node = &root;
        while (*node != nullptr) {
            if (id < (*node)->id) {
                node = &(*node)->left;
            } else if (id > (*node)->id) {
                node = &(*node)->right;
            } else {
                cout << "Employee with ID " << id << " already exists.";
                return;
            }
        }
        *node = new EmployeeNode(id, name, dept);
    }

    void search(int id) {
        EmployeeNode* node = root;
        while (node != nullptr) {
            if (node->id == id) {
                cout << "Found Employee - ID: " << node->id << ", Name: " << node->name << ", Department: " << node->dept << endl;
                return;
            } else if (id < node->id) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    void deleteNode(int id) {
        EmployeeNode** node = &root;
        while (*node != nullptr && (*node)->id != id) {
            if (id < (*node)->id) {
                node = &(*node)->left;
            } else {
                node = &(*node)->right;
            }
        }

        if (*node == nullptr) {
            cout << "Employee with ID " << id << " does not exist." << endl;
            return;
        }

        EmployeeNode* temp = *node;
        if ((*node)->left == nullptr) {
            *node = (*node)->right;
        } else if ((*node)->right == nullptr) {
            *node = (*node)->left;
        } else {
            EmployeeNode** minNode = &(*node)->right;
            while ((*minNode)->left != nullptr) {
                minNode = &(*minNode)->left;
            }
            (*node)->id = (*minNode)->id;
            (*node)->name = (*minNode)->name;
            (*node)->dept = (*minNode)->dept;
            temp = *minNode;
            *minNode = (*minNode)->right;
        }
        delete temp;
    }

    void inOrderTraversal() {
        struct StackEntry {
            EmployeeNode* node;
            bool visited;
        };

        StackEntry stack[100];
        int stackSize = 0;
        EmployeeNode* current = root;

        while (current != nullptr || stackSize > 0) {
            while (current != nullptr) {
                stack[stackSize++] = {current, false};
                current = current->left;
            }

            StackEntry& top = stack[--stackSize];
            current = top.node;

            if (!top.visited) {
                top.visited = true;
                cout << "ID: " << current->id << ", Name: " << current->name << ", Department: " << current->dept << endl;
                current = current->right;
            } else {
                current = nullptr;
            }
        }
    }

    void findMin() {
        EmployeeNode* node = root;
        if (!node) {
            cout << "Tree is empty." << endl;
            return;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        cout << "Min Employee - ID: " << node->id << ", Name: " << node->name << ", Department: " << node->dept << endl;
    }

    void findMax() {
        EmployeeNode* node = root;
        if (!node) {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->right != nullptr) {
            node = node->right;
        }
        cout << "Maximum Employee - ID: " << node->id << ", Name: " << node->name << ", Department: " << node->dept << endl;
    }
};

int main() {
    Tamia_004 bst;

    bst.insert(10, "Tamia", "CEO");
    bst.insert(35, "Bushra Ansar", "Manager");
    bst.insert(48, "Bushra Atiq", "Cook");
    bst.insert(26, "Hareem", "Peon");

    bst.inOrderTraversal();
   
    cout << endl;
   
    bst.search(26);
   
    cout << endl;
   
    bst.search(51);
   
    cout << endl;
   
    bst.findMin();
   
    cout << endl;
   
    bst.findMax();
   
    cout << endl;

    bst.deleteNode(26);
   
    bst.inOrderTraversal();
   
    cout << endl;
   
    bst.deleteNode(59);
   
    cout << endl;
   
    bst.insert(67, "Sadia", "Supply Manager");
   
    cout << endl;
   
    bst.inOrderTraversal();

    return 0;
}