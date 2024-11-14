#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int value){
			data = value;
			next = NULL;
		}
};
class Tamia_004{
private:
    Node* front;
    Node* rear;
public:
	// constructor
    Tamia_004() {
        front = rear = nullptr;
    }
	bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        if (isEmpty()) {  
            front = rear = newNode;
            newNode->next = front;  
        } else {
            rear->next = newNode;  
            rear = newNode;       
            rear->next = front;    
        }
    }

    void dequeue() {
        if (isEmpty()) {  
            cout << "Queue is underflowing." << endl;
            return;
        }
// agar front or rear ik hi position mn hain to front ko delete kardo 
// or dono ko null pe point kardo.
        if (front == rear) {  
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;   
            rear->next = front;    
            delete temp;
        }
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is underflowing." << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is underflowing." << endl;
            return;
        }

        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);  
        cout << endl;
    }
};

int main() {
    Tamia_004 T;

    T.enqueue(440);
	T.display();
	T.dequeue();
    T.enqueue(23);
    T.enqueue(190);
    T.enqueue(57);
    T.display(); 
    
    cout << "Front element: " << T.Front() << endl;  
    
	T.dequeue();
    T.display();  

    return 0;
}
