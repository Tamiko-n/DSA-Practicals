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
    Tamia_004() {
        front = rear = nullptr;
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
    }
    static void concatenate(Tamia_004 &L, Tamia_004 &M) {
        if (L.front == nullptr) {
            L.front = M.front;
            L.rear = M.rear;
            return;
        }
        if (M.front == nullptr)
            return;
        
        // Link the end of list L to the start of list M
        L.rear->next = M.front;
        M.front->prev = L.rear;
        
        // Update the rear of list L to be the rear of list M
        L.rear = M.rear;
    }

    void sortDescending() {
        for (Node* i = front; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }
    void display() const {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Tamia_004 L, M;
    for (int i = 2; i <= 10; i += 2) L.insertRear(i);
    for (int i = 1; i <= 9; i += 2) M.insertRear(i);
    cout << "List L (Even numbers): ";
    L.display();

    cout << "List M (Odd numbers): ";
    M.display();

    Tamia_004::concatenate(L, M);
    cout << "Concatenated List (L + M): ";
    L.display();
    
    L.sortDescending();
    cout << "Sorted List in Descending Order: ";
    L.display();
    return 0;
}
