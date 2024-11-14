#include<iostream>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Tamia_004{
	public:
		Node *deleteDuplicates(Node *head) {
    	Node *current = head;

    while (current != NULL && current->next != NULL) {
      
        if (current->data == current->next->data) {
            Node *next_next = current->next->next;
            current->next = next_next;
        }
        else
            current = current->next;
    }
    return head;
}

void display(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
};
int main() {
    Tamia_004 T;
    
    Node *head = new Node(9);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(13);
    head->next->next->next->next->next = new Node(21);

    cout << "Linked list before duplicate removal:" << endl;
    T.display(head);

    head = T.deleteDuplicates(head);

    cout << "Linked list after duplicate removal:" << endl;
    T.display(head);

    return 0;
}
