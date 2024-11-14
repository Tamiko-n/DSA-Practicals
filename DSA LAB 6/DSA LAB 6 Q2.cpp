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
    Node* top;
	int size;
public:
	// constructor
    Tamia_004() {
        top = nullptr;
        size = 0;
    }
	bool isEmpty() {
        return top == nullptr;
    }
    int isSize(){
    	return size;
	}
    void Push(int value) {
        Node* temp = new Node(value);
        if (temp == NULL) {
        	cout << "Stack is underflowing." << endl;
		    return;    
        } else {
            temp->next = top;  
            top = temp;
			size++;       
            cout << "Pushed " << value << " into the stack." << endl;
        }
    }

    void Pop() {
        if (isEmpty()) {  
            cout << "Stack is underflowing." << endl;
            return;
        }
        else {
           Node* temp = top;
           cout << "Popped "<< top->data << " from stack" << endl;
           top = top->next;   
           delete temp;
           size--;
        }
    }

    int Peek() {
        if (isEmpty()) {
            cout << "Stack is underflowing." << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Tamia_004 T;

    T.Push(46);
    T.Push(3);
	T.Pop();
	T.Push(97);
    T.Push(23);
    T.Push(36);
	T.Push(18);
	cout << "Is stack empty? " << T.isEmpty() << endl;
	cout << "Size is:" << T.isSize() << endl;
    cout << "Front element: " << T.Peek() << endl;  
	T.Pop();
	cout << "Size is:" << T.isSize() << endl;

    return 0;
}
