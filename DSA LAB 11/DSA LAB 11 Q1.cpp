#include <iostream>
#include <vector>
using namespace std;
class Tamia_004 {
public:
    void heapSort(vector<int>& n) {
        int s = n.size();
        for (int i = s/2 - 1; i >= 0; i--) {
            heapify(n, s, i);
        }
        for (int i = s - 1; i >= 0; i--) {
            swap(n[0], n[i]);
            heapify(n, i, 0);
        }
    }
private:
    void heapify(vector<int>& n, int s, int root) {
        int large = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < s && n[left] > n[large]) large = left;
        if (right < s && n[right] > n[large]) large = right;
        if (large != root) {
            swap(n[root], n[large]);
            heapify(n, s, large);
        }
    }
};
int main() {
    Tamia_004 T;
    vector<int> n;
    n.push_back(89);
    n.push_back(14);
    n.push_back(67);
    n.push_back(28);
    n.push_back(25);
    n.push_back(40);
 
    cout << "The values before heap sort are: ";
    for (int i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;
    T.heapSort(n);
    cout << "The values after heap sort are: ";
    for (int i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;
    return 0;
}
