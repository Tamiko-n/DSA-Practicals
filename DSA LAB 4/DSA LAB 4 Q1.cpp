#include <iostream> 
using namespace std; 
class Tamia_Lab04 { 
    public:
    void ModifiedBubbleSort(int *a, int n) {         
       // Ye function do cheezein leta hai: numbers ki list (a) aur kitne numbers hain (n).
        
        bool swapped; // Ye batata hai ke humne koi numbers swap kiye hain ya nahi.
        
        // Ye pehla loop numbers ki list mein jata hai.
        for (int i = 0; i < n - 1; i++) {
            swapped = false; // Hum shuru karte hain ke humne koi numbers swap nahi kiye hain ab tak.
            
            // Ye doosra loop har number ke pair ko check karta hai.
            for (int j = 0; j < n - i - 1; j++) {
                // Agar pehla number dusre se bara hai,
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]); // Hum unhe swap karte hain taake chhota pehle aaye.
                    swapped = true; // humne swap ko true kiya!
                }
            }
            
            // Agar humne is poore loop mein koi swap nahi kiya,
            if (!swapped) {
                break; // Hum loop ko break kardete hain qk numbers pehle se hi sorted hain!
            }
        }
        
        for(int i = 0; i < n; i++) {
            cout << a[i] << " "; 
        }
        cout << endl; 
    }
};
int main() { 
    Tamia_Lab04 T; 
    
    int array[] = {2, 4, 11, 1990, 462, 6, 8}; 
    int n = sizeof(array) / sizeof(array[0]); 
    
    T.ModifiedBubbleSort(array, n); 
    return 0; 
}
