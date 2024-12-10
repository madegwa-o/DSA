#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found target
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = sequentialSearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
