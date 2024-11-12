#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Tamia_004 {
public:
    vector<int> pancake(vector<int>& a) {
        vector<int> answer; 
        int n = a.size(); 
        
        // Yeh loop poore array ko reverse karke sort karega
        for (int j = n; j > 1; j--) {
            // Current size tak maximum element ka index dhoondte hain
            int max_index = findMaxIndex(a, j);
            
            // Agar maximum element apni sahi jagah par nahi hai
            if (max_index != j - 1) {
                // Agar maximum element pehle se aage nahi hai toh pehle usay aage le aate hain
                if (max_index != 0) {
                    flip(a, max_index + 1); // Flip karte hain
                    answer.push_back(max_index + 1); // k-value ko result mein dalte hain
                }
                
                // Ab maximum element ko sahi position par le aate hain
                flip(a, j);
                answer.push_back(j); // Aur uska k-value bhi result mein daal dete hain
            }
        }
        
        return answer; 
    }
    
private:
    // Yeh function maximum element ka index dhoondta hai
    int findMaxIndex(vector<int>& a, int n) {
        int max_index = 0; // Pehle se assume karte hain pehla element maximum hai
        for (int i = 1; i < n; i++) { 
            if (a[i] > a[max_index]) { 
                max_index = i;
            }
        }
        return max_index; 
    }
    
    // Yeh function array ko 0 se k-1 tak reverse karta hai
    void flip(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.begin() + k); 
    }
};

int main() {
    Tamia_004 T; 
    vector<int> a = {3, 2, 4, 1}; 
    vector<int> flips = T.pancake(a); 
    cout << "Sorted array: "; 
    for (int num : a) {
        cout << num << " "; 
}
    cout << endl;
    cout << "Flip sequence: "; 
    for (int flip : flips) {
        cout << flip << " "; 
}
    cout << endl;
    return 0; 
}
