#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string URL = "") {
	url = URL;
	prev = next = nullptr;
	}
};

class Tamia_004 {
    Node* current;

public:
    Tamia_004(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        cout << "Visited: " << url << endl;
    }

    string back(int steps) {
        while (steps-- > 0 && current->prev != nullptr) {
            current = current->prev;
        }
        cout << "After going back, current page is: " << current->url << endl;
        return current->url;
    }

    string forward(int steps) {
        while (steps-- > 0 && current->next != nullptr) {
            current = current->next;
        }
        cout << "After going forward, current page is: " << current->url << endl;
        return current->url;
    }
};

int main() {
    Tamia_004 browserHistory("Haroon.com");

    browserHistory.visit("AliBaBa.com");
    browserHistory.visit("Temu.com");
    browserHistory.visit("Daraz.com");

    browserHistory.back(1); 
    browserHistory.back(1);  
    browserHistory.forward(1);  

    browserHistory.visit("Yango.com");  

    browserHistory.back(2);  
    browserHistory.forward(2); 
    return 0;
}
