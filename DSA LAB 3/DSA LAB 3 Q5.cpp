#include <iostream>
#include <queue>
using namespace std;
class Tamia_Lab03{
private:
    int value;          
    int k;             
    queue<int> Q;  
    int count;          

public:
    // Constructor
    Tamia_Lab03(int value,int k):value(value),k(k),count(0){}

    bool consec(int N) {
        if (Q.size() == k) {
            int removed = Q.front();
            Q.pop();
            if (removed == value) {
                count--;
            }
        }
        Q.push(N);
        if (N == value) {
            count++;
        }
        return Q.size() == k && count == k;
    }
};
int main() {
    Tamia_Lab03 T(4, 3); 
    cout << boolalpha;
    cout << T.consec(4) << endl; 
    cout << T.consec(4) << endl; 
    cout << T.consec(4) << endl; 
    cout << T.consec(3) << endl; 
    return 0;
}
