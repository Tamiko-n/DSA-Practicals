#include <iostream>
using namespace std;
class Tamia_Lab04{
	public:
    void BubbleSort(int *a, int n) { 
        // Ye function do cheezein leta hai: numbers ki list (a) aur kitne numbers hain (n).
        
        bool sorted = true; // Ye batata hai ke numbers pehle se sorted hain ya nahi.

        // Ye loop har number ko check kar raha hai.
        for (int i = 0; i < n; i++) {
            // Agar pehla number dusre se bara hai to sorted nahi hai.
            if (i == 0 && a[i] > a[i + 1]) sorted = false; 
            // Agar akhri number pehle se chota hai to sorted nahi hai.
            else if (i == n - 1 && a[i] < a[i - 1]) sorted = false; 
            // Agar koi number apne last se chota aur next se bara hai to sorted nahi hai.
            else if (a[i] < a[i - 1] && a[i] > a[i + 1]) sorted = false; 
        }
        
        // Agar sab numbers pehle se sorted hain,to hum Function ko yahan se return karte hain.
        if (sorted) {
            cout << "Array is sorted"; 
            return; 
        }
        
        // Agar array sorted nahi hai, to ab hum sorting shuru karte hain.
        for (int i = 0; i < n - 1; i++) { // Ye loop puri array ko check karta hai.
            for (int j = 0; j < n - i - 1; j++) { // Ye loop har number ke pair ko check karta hai.
                // Agar pehla number dusre se bara hai,to hum unhe swap karte hain.
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]); 
                }
            }
        }
    }
    
    // Ye function toys ka maximum number batata hai jo hum 'k' ke andar le sakte hain.
    int MaxNumOfToys(int *a, int k, int n) { 
        int c = 0; // Hum ek counter rakhte hain jo toys ko  count karega.
        
        // Ye loop har toy ko check karta hai jab tak k zyada hai ya toys khatam nahi hote.
        for (int i = 0; i < n && k > 0; i++) {
            k -= a[i]; // Hum k se toy ka price km krrahe hain.
            c++; 
        }
        
        // Agar k negative ho jata hai, to humne ek toy zyada count kiya hai.
        if (k < 0)
            c--; // Isliye hum counter ko ek se km karrahe hain.
        
        return c; 
    }
};
int main(){
	Tamia_Lab04 T;
	int k;
	cout << "Enter the value of k" << endl;
	cin >> k;
	int array[] = {1,12,5, 111,200,1000,10};
	int n = sizeof(array)/sizeof(array[0]);
	T.BubbleSort(array,n);
	cout <<"The number of toys are:";
	cout << T.MaxNumOfToys(array,k,n);
	return 0;
}