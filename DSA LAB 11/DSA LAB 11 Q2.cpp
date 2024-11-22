#include <iostream>
#include <vector>
using namespace std;
class Tamia_004 {
public:
    vector<int> FQ(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || k == 0) return result;
        int maxFreq = 0;
        vector<int> frequency(1001, 0); 
        for (int num : nums) {
            frequency[num]++;
            maxFreq = max(maxFreq, frequency[num]);
        }
        vector<vector<int>> QF(maxFreq + 1); 
        for (int i = 0; i < frequency.size(); i++) {
            if (frequency[i] > 0) {
                QF[frequency[i]].push_back(i);
            }
        }
        for (int i = maxFreq; i >= 0; i--) {
            if (QF[i].empty()) continue;
            for (int num : QF[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
int main() {
    Tamia_004 T;
    vector<int> n;
    int values[] = {3, 9, 9, 5, 6, 6};
    for (int i = 0; i < 6; i++) {
        n.push_back(values[i]);
    }
     int k = 2;
     cout << "The given values are: ";
    for (int i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;
     vector<int> result = T.FQ(n, k);
    cout << "The " << k << " most frequent elements are: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
