#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

class Tamia_Lab04 {
public:
	/* 
	Hum 5 functions introduce karwarahe hain:
	Bubble sort,Insertion sort,Selection sort,random value,print array.Humne tamam sorting 
	functions mn do new parameters comparasions or swaps ko introdue kiya h jo number of 
	comparasions or swaps ko count karega take best or worst sorting technique k pata chal sake.
	*/

    // Sorting techniques ke functions aur analysis
    void BubbleSort(int *a, int n, int &comparisons, int &swaps) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comparisons++; 
                if (a[j] > a[j] + 1) { 
                    swap(a[j], a[j + 1]);
                    swaps++; 
                }
            }
        }
    }

    void InsertionSort(int *a, int n, int &comparisons, int &swaps) {
        for (int i = 1; i < n; i++) {
            int key = a[i]; // Current number ko key bana lo
            int j = i - 1;
            while (j >= 0 && a[j] > key) { // Jab tak previous number key se bara hai
                comparisons++; 
                a[j + 1] = a[j]; // Shift kar do
                j--;
                swaps++; 
            }
            a[j + 1] = key; // Key ko sahi jagah par daal do
            if (j >= 0) comparisons++; // Last comparison for insertion
        }
    }

    void SelectionSort(int *a, int n, int &comparisons, int &swaps) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i; // Minimum number ka index
            for (int j = i + 1; j < n; j++) {
                comparisons++; 
                if (a[j] < a[minIndex]) { // Agar current number minimum se chota hai
                    minIndex = j; // Update minimum index
                }
            }
            if (minIndex != i) { 
                swap(a[minIndex], a[i]);
                swaps++; 
            }
        }
    }

    void randomValue(int *a, int n, int range) {
        srand(static_cast<unsigned int>(time(0))); 
        for (int i = 0; i < n; i++) {
            a[i] = rand() % range; 
        }
    }

    void printArray(int *a, int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " "; 
        }
        cout << endl;
    }
};

int main() {
    Tamia_Lab04 T; 
    int n, range;

    cout << "Enter the number of elements you want to sort: ";
    cin >> n; 
    cout << "Enter the range for random values: ";
    cin >> range; 

    int *array = new int[n]; // Dynamically array ke liye memory allocate karo
    T.randomValue(array, n, range); 

    cout << "Original array: ";
    T.printArray(array, n); 
    int comparisons = 0, swaps = 0;

    cout << "Choose sorting technique (1: Bubble, 2: Insertion, 3: Selection): ";
    int choice;
    cin >> choice; 

    switch (choice) {
        case 1:
            T.BubbleSort(array, n, comparisons, swaps);
            cout << "Bubble Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
            break;
        case 2:
            comparisons = 0; 
            swaps = 0; 
            T.InsertionSort(array, n, comparisons, swaps);
            cout << "Insertion Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
            break;
        case 3:
            comparisons = 0; 
            swaps = 0; 
            T.SelectionSort(array, n, comparisons, swaps);
            cout << "Selection Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
            break;
        default:
            cout << "Invalid choice!" << endl; 
            delete[] array; 
            return 1;
    }

    cout << "Sorted array: ";
    T.printArray(array, n); 

    // Comparison analysis
    cout << "\nBest Technique: ";
    if (comparisons == 0) {
        cout << "No comparisons made.";
    } else if (comparisons <= 10) {
        cout << "Best performance achieved!";
    } else {
        cout << "Performance may vary.";
    }

    delete[] array; 
    return 0; 
}
