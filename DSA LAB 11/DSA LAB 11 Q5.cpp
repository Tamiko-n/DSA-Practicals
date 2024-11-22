#include <bits/stdc++.h>
using namespace std;
class Tamia_004 {
public:
    vector<double> SlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        priority_queue<int> maxHeap; // Max-heap for the lower half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the upper half
        // Lambda to rebalance the heaps
        auto balanceHeaps = [&]() {
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        };
        // Lambda to add a number to the heaps
        auto addNum = [&](int num) {
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
            balanceHeaps();
        };
        // Lambda to remove a number from the heaps
        auto removeNum = [&](int num) {
            if (!maxHeap.empty() && num <= maxHeap.top()) {
                // Create a temporary max heap without the number to be removed
                priority_queue<int> temp;
                while (!maxHeap.empty()) {
                    if (maxHeap.top() != num) temp.push(maxHeap.top());
                    maxHeap.pop();
                }
                maxHeap = temp;
            } else {
                // Create a temporary min heap without the number to be removed
                priority_queue<int, vector<int>, greater<int>> temp;
                while (!minHeap.empty()) {
                    if (minHeap.top() != num) temp.push(minHeap.top());
                    minHeap.pop();
                }
                minHeap = temp;
            }
            balanceHeaps();
        };
        // Process each sliding window
        for (int i = 0; i < nums.size(); i++) {
            addNum(nums[i]);
            if (i >= k - 1) {
                // Calculate median
                if (maxHeap.size() > minHeap.size()) {
                    medians.push_back(maxHeap.top());
                } else {
                    medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
                }
                // Remove the element going out of the sliding window
                removeNum(nums[i - k + 1]);
            }
        }
        return medians;
    }
};
int main() {
    Tamia_004 T;
    vector<int> n = {1, 3, -1, -3, 5, 3, 6, 7};
    int Size = 4;
    vector<double> median = T.SlidingWindow(n, Size);
    cout << "Medians for test case 4: ";
    for (double med : median) {
        cout << fixed << setprecision(3) << med << " ";
    }
    cout << endl;
    return 0;
}
