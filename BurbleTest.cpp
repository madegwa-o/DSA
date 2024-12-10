#include <iostream>

using namespace std;


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int bubbleIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[bubbleIndex] > arr[j]) {
                swap(arr[bubbleIndex], arr[j]);
            }
            cout << endl;
            printArray(arr, n);
        }

        
        // Print the array after each outer loop iteration
        cout << "Array after iteration " << i+1 << ": ";
        printArray(arr, n);
    }
}


void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}



int main()
{
    int arr[] = {90,64, 34, 25, 12, 22, 11,};
    int n = sizeof(arr) / sizeof(arr[0]);
   
   cout << "initial state of the array" << ": ";
    printArray(arr, n);
    bubbleSort(arr, n);

    return 0;
}