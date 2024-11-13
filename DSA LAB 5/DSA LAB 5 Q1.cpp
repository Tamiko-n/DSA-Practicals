#include <iostream>
#include <vector>
using namespace std;
class Tamia_004 {
private:
    // Yeh function array ko pivot ke hisaab se partition karta hai
    int partition(vector<int>& arr, int start, int end) {
        int pivot = arr[end]; // Last element ko pivot bana lete hain
        int i = start - 1; // Smaller element ka index

        // Elements ko rearrange karte hain
        for (int j = start; j < end; j++) {
            if (arr[j] < pivot) { // Agar current element pivot se chota hai
                i++; // Smaller element ka index barhate hain
                swap(arr[i], arr[j]); // Swap karte hain
            }
        }
        swap(arr[i + 1], arr[end]); // Pivot ko sahi position par rakhte hain
        return i + 1; // Pivot ka index return karte hain
}
public:
    void quickSort(vector<int>& arr) {
        int n = arr.size(); // Array ka size nikalte hain
        int* start = new int[n]; // Start indices ke liye array banate hain
        int* end = new int[n]; // End indices ke liye array banate hain
        int top = -1; // Top index ko initialize karte hain

        // Pura array ko sort karne ke liye start aur end indices push karte hain
        start[++top] = 0; // Pehli sub-array ka start index
        end[top] = n - 1; // Pehli sub-array ka end index

        while (top >= 0) {
            int s = start[top]; 
            int e = end[top--]; 

            // Agar sub-array mein ek se zyada elements hain
            if (s < e) {
                int pivotIndex = partition(arr, s, e); // Partition function call karte hain

                // Left sub-array ko push karte hain
                start[++top] = s; // Start index
                end[top] = pivotIndex - 1; // End index

                // Right sub-array ko push karte hain
                start[++top] = pivotIndex + 1; // Start index
                end[top] = e; // End index
            }
        }
        delete[] start; // Memory ko free karte hain
        delete[] end; // Memory ko free karte hain
    }
};

int main() {
    Tamia_004 T; 
    vector<int> a = {76,90,1,47,103,71,19,22,74,54}; 
    T.quickSort(a); 
    cout << "Sorted array: "; 
    for (int n : a) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
