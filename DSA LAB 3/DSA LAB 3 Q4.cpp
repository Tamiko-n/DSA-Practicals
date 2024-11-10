#include <iostream>
#include <queue>
using namespace std;
class Tamia_Lab03 {
private:
    int n;  
    int k;  
public:
    // Constructor 
    Tamia_Lab03(int N, int C) : n(N), k(C) {}

    int findWinner() const {
        queue<int> q;
        // Initiazation
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        // Jb tk queue 1 tk nhi ajata tb tk front element ko k-1 time rear mn shift karain gain 
        while (q.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                q.push(q.front());
                q.pop();
            }
            // K-th element ko eleminate kardein gain
            q.pop();
        }
        // Aakhir mn jo bache ga wohi winner hoga.
        return q.front();
    }
};

int main() {
    int n,k;
    cout << "Enter the number of friends: ";
    cin >> n;
    cout << "Enter the count: ";
    cin >> k;
    Tamia_Lab03 T(n,k);
    int w = T.findWinner();
    cout << "The winner is friend number: " << w << endl;
    return 0;
}
