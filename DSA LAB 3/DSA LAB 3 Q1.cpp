#include <iostream>
#include <stdexcept>
using namespace std;
// COUNT TO KEEP TRACK OF NO OF ELEMENTS, SIZE TO SHOW CAPACITY OF QUEUE.
class Tamia_Lab03 {
private:
    int* queue;       
    int Size;         
    int front;        
    int rear;         
    int count;        

public:
    // Constructor
    Tamia_Lab03(int size) : Size(size), front(0), rear(-1), count(0) {
        if (size <= 0) {
            throw invalid_argument("Queue size must be positive.");
        }
        queue = new int[Size];
    }

    // Destructor
    ~Tamia_Lab03() {
        delete[] queue;
    }

    // ELEMENT REAR SE INSERT KARAINGAIN.
    void enqueue(int N) {
        if (isFull()) {
            throw overflow_error("Queue is overflowing.");
        }
        rear = (rear + 1) % Size;
        queue[rear] = N;
        count++;
    }

    // ELEMENT FRONT SE DELETE KARAINGAIN.
    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        int value = queue[front];
        front = (front + 1) % Size;
        count--;
        return value;
    }

    // Agar koi bhi front element nhi h to error throw karega otherwise front return karega. 
    int Front() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return queue[front];
    }

    // Agar koi bhi rear element nhi h to error throw karega otherwise rear return karega.
    int Rear() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return queue[rear];
    }

   // HUMNE ISFULL,ISEMPTY OR SIZE K FUNCTION BANAYA HE OR USE ENQUE,DEQUE,FRONT,REAR MN CALL KIYA H.
    bool isFull() const {
        return count == Size;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    // Display all elements in the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
       int i = front;
        int totalElemets = count;
        while (totalElemets--) {
            cout << queue[i] << " ";
            i = (i + 1) % Size;
        }
        cout << endl;
    }
};

int main() {
    try {
        Tamia_Lab03 T(4);
        T.enqueue(153);
        T.enqueue(143);
        T.enqueue(567);
        T.enqueue(95);
        
        cout << "Queue after enqueuing 4 elements: ";
        T.display();

        T.dequeue();
        T.dequeue();
        cout << "Queue after dequeuing 2 element: ";
        T.display();

        T.enqueue(45);
        T.enqueue(39);
        cout << "Queue after enqueuing 2 more elements: ";
        T.display();

        cout << "Front element: " << T.Front() << endl;
        cout << "Rear element: " << T.Rear() << endl;

        cout << "Size of the queue: " << T.size() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
