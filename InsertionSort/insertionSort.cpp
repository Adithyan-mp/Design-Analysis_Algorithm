#include<iostream>
using namespace std;

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n) {
    // Iterate through each element in the array
    for (int i = 1; i < n; i++) {
        // Store the current element in 'key'
        int key = arr[i];
        // Initialize 'j' to the index of the element before the current one
        int j = i - 1;

        // Move elements greater than 'key' to one position ahead of their current position
        // until the correct position for 'key' is found
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place 'key' at its correct position in the sorted array
        arr[j + 1] = key;
    }
}

int main() {
    // Example array
    int arr[] = {12, 11, 13, 5, 6};
    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the insertionSort function to sort the array
    insertionSort(arr, n);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
