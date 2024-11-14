#include <iostream>
#include <stack>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int d) { 
        data = d; 
        next = nullptr;
    }
};
class Tamia_004{
	public:
		bool Palindrome(Node* head) {
    	Node* currentNode = head;

    stack<int> s;
    while (currentNode != nullptr) {
        s.push(currentNode->data);
        currentNode = currentNode->next;
    }
    while (head != nullptr) {
        int c = s.top();
        s.pop();
        if (head->data != c) {
            return false;
        }
        head = head->next;
    }
    	return true;
	}
};
int main() {
  	Tamia_004 T;
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(55);
    head->next->next->next = new Node(22);
    head->next->next->next->next = new Node(11);

    bool result = T.Palindrome(head);
    if (result)
        cout << "True\n";
    else
        cout << "False\n";
    return 0;
}
