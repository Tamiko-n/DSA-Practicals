#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Tamia_004 {
public:
    Node* mergeSortedList(Node* a, Node* b) {
        Node* result = NULL;

        // Base condition
        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        // recursion
        if (a->data <= b->data) {
            result = a;
            result->next = mergeSortedList(a->next, b);
        } else {
            result = b;
            result->next = mergeSortedList(a, b->next);
        }
        return result;
    }

    void display(Node* a, Node* b) {
        Node* res = mergeSortedList(a, b);
        Node* temp = res;
        cout << "Merged Linked List is:" << endl;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Node* a = new Node(2);
    a->next = new Node(4);
    a->next->next = new Node(6);
    a->next->next->next = new Node(8);

    Node* b = new Node(1);
    b->next = new Node(3);
    b->next->next = new Node(5);
    b->next->next->next = new Node(10);

    Tamia_004 T;
    T.display(a, b);  

    return 0;
}
