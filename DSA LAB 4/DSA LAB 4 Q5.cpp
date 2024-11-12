#include <iostream>
using namespace std;

class Tamia_004 {
public:
	// we are bubble sort algorithm.
    void bubbleSort(int nums[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};

int main() {
    Tamia_004 T;
    int nums1[] = {2, 0, 2, 1, 1, 0};
    int nums2[] = {2, 0, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    T.bubbleSort(nums1, size1);
    T.bubbleSort(nums2, size2);
    cout << "Sorted array 1: ";
    for (int i = 0; i < size1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    cout << "Sorted array 2: ";
    for (int i = 0; i < size2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}
