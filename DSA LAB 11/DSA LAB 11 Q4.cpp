#include <bits/stdc++.h>
using namespace std;
class Tamia_004 {
public:
    double cost(vector<int>& q, vector<int>& wage, int k) {
        int n = q.size();
        vector<double> ratios(n);
        // Calculate the wage-to-quality ratio for each worker
        for (int i = 0; i < n; i++) {
            ratios[i] = (double)wage[i] / q[i];
        }
        // Sort workers based on their wage-to-quality ratio
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return ratios[a] < ratios[b];
        });
        // Max-heap to maintain the k workers with the highest qualities
        priority_queue<int> maxHeap;
        int sumQ = 0;
        double minCost = INT_MAX;
        // Calculate the cost for the first k workers
        for (int i = 0; i < k; i++) {
            sumQ += q[indices[i]];
            maxHeap.push(q[indices[i]]);
        }
        minCost = ratios[indices[k - 1]] * sumQ;
        // Iterate through the remaining workers and adjust the heap
        for (int i = k; i < n; i++) {
            sumQ -= maxHeap.top();  // Remove the largest quality from the heap
            maxHeap.pop();
            sumQ += q[indices[i]];  // Add the current worker's quality
            maxHeap.push(q[indices[i]]);
            // Calculate and update the minimum cost
            minCost = min(minCost, ratios[indices[i]] * sumQ);
        }
        return minCost;
    }
};
int main() {
    Tamia_004 T;
    vector<int> q = {95, 76, 84, 67};
    vector<int> wage = {1200, 1150, 1000, 860};
    int k = 3;
    cout << "Minimum cost to hire " << k << " workers: " << T.cost(q, wage, k) << endl;
    return 0;
}
