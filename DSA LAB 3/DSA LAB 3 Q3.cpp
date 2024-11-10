#include <iostream>
#include <stdexcept>
using namespace std;

class Tamia_Lab03 {
private:
    int* queue;
    int Size;
    int front;
    int rear;
    int count;

public:
    // Constructor
    Tamia_Lab03(int k) : Size(k), front(0), rear(-1), count(0) {
        if (k <= 0) {
            throw invalid_argument("Queue size must be positive.");
        }
        queue = new int[k];
    }

    // Destructor
    ~Tamia_Lab03() {
        delete[] queue;
    }
    bool insertFront(int n) {
        if (isFull()) {
            return false; 
        }
        front = (front - 1 + Size) % Size;
        queue[front] = n;
        count++;
        return true;
    }
    
    bool insertLast(int n) {
        if (isFull()) {
            return false; 
        }
        rear = (rear + 1) % Size;
        queue[rear] = n;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false; 
        }
        front = (front + 1) % Size;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false; 
        }
        rear = (rear - 1 + Size) % Size;
        count--;
        return true;
    }

    int getFront() const {
        if (isEmpty()) {
            return -1;
        }
        return queue[front];
    }

    int getRear() const {
        if (isEmpty()) {
            return -1; 
        }
        return queue[rear];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == Size;
    }
};

int main() {
    try {
        Tamia_Lab03 myCircularDeque(3);
        
        //In order to print true/false instead of 0/1 i have to add a manipulator known as boolalpha which will print values as true/false.
        cout << boolalpha;
		cout << myCircularDeque.insertLast(1) << endl;  // return True
        cout << myCircularDeque.insertLast(2) << endl;  // return True
        cout << myCircularDeque.insertFront(3) << endl; // return True
        cout << myCircularDeque.insertFront(4) << endl; // return False, the queue is full.
        
        cout << myCircularDeque.getRear() << endl;      // return 2
        cout << myCircularDeque.isFull() << endl;       // return True
        cout << myCircularDeque.deleteLast() << endl;   // return True
        cout << myCircularDeque.insertFront(4) << endl; // return True
        cout << myCircularDeque.getFront() << endl;     // return 4
        
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
