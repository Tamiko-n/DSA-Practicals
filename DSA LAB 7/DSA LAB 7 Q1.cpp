#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class Tamia_004 {
    Node* rear;
public:
    Tamia_004(){
    	rear = nullptr;
	}  
   void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueuing " << value << endl;
    }

    void dequeue() {
        if (rear == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = rear->next;
        int dequeuedValue = temp->data;
        if (rear == rear->next) {
            rear = nullptr;
        } else {
            rear->next = temp->next;
        }
        delete temp;
        cout << "Dequeuing " << dequeuedValue << endl;
    }

    void display() {
        if (rear == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = rear->next;
        cout << "Queue contents: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    Tamia_004 T;
    T.enqueue(44);
    T.enqueue(34);
    T.display();
    T.enqueue(123);
    T.dequeue();
    T.display();
    T.enqueue(67);
    T.enqueue(98);
    T.display();
    return 0;
}