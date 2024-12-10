#include <iostream>

using namespace std;


void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
    }

}
    

int main() {

    int arr[] = {8,2,7,4,5,1,9,3};

    int length = 8;
    insertionSort(arr, length);
    printArray(arr, length);

    return 0;
}