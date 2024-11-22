#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Tamia_004 {
public:
    string FQSort(string str) {
        vector<int> count(256, 0);
        for (char ch : str) {
            count[ch]++;
        }
        vector<pair<int, char>> freqChars;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                freqChars.push_back({count[i], char(i)});
            }
        }
        sort(freqChars.begin(), freqChars.end(), [](pair<int, char> a, pair<int, char> b) {
            return a.first > b.first;
        });
        string sortedStr;
        for (auto& [freq, ch] : freqChars) {
            sortedStr += string(freq, ch);
        }
        return sortedStr;
    }
};
int main() {
    Tamia_004 T;
    string input = "CFCSCECAAAA";
    string output = T.FQSort(input);
    cout << "Sorted string according to frequency: " << output << endl;
    return 0;
}
