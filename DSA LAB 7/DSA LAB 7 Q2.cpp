#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};
class Tamia_004 {
    Node* front;
    Node* rear;

public:
    Tamia_004(){
		front = rear = nullptr;
    }
    void insertFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;
        if (front != nullptr)
            front->prev = newNode;
        else
            rear = newNode;
        front = newNode;
        cout << "Inserting " << value << " at the front." << endl;
    }

    void insertRear(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;
        if (rear != nullptr)
            rear->next = newNode;
        else
            front = newNode;
        rear = newNode;
        cout << "Inserting " << value << " at the rear." << endl;
    }

    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        Node* temp = front;
        cout << "Deleting " << temp->data << " from front." << endl;
        front = front->next;
        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr;
        delete temp;
    }

    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        Node* temp = rear;
        cout << "Deleting " << temp->data << " from rear." << endl;
        rear = rear->prev;
        if (rear != nullptr)
            rear->next = nullptr;
        else
            front = nullptr;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Deque contents: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Tamia_004 T;
    T.deleteFront();           
    T.insertFront(43);          
    T.insertRear(12);         
    T.insertFront(67);          
    T.display();                
    T.deleteRear();             
    T.insertFront(90);          
    T.display();                
    return 0;
}
