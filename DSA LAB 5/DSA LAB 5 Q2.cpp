#include <iostream>
#include <vector>
using namespace std;
class Tamia_MergeSort {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1; // Left half ki size
        int n2 = right - mid; // Right half ki size

        // Temporary arrays banate hain
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        // Elements ko temporary arrays mein daalte hain
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        // Merging the temporary arrays
        int i = 0, j = 0, k = left; // i for leftArr, j for rightArr, k for original array
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Agar leftArr mein kuch bacha ho
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Agar rightArr mein kuch bacha ho
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr) {
        int n = arr.size();
        for (int size = 1; size < n; size *= 2) { // Sub-array size
            for (int left = 0; left < n; left += 2 * size) {
                int mid = min(left + size - 1, n - 1); // Mid point
                int right = min(left + 2 * size - 1, n - 1); // Right point

                if (mid < right) { // Merge only if valid
                    merge(arr, left, mid, right);
                }
            }
        }
    }
};
int main() {
    Tamia_MergeSort T;
    vector<int> a = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    for (int n : a) {
        cout << n << " ";
    }
    cout << endl;
    T.mergeSort(a);
    cout << "Sorted array: ";
    for (int n : a) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
 