/* Kyle Wood - Sort - 8/26/24 */

/*
Instructions:
Write a sort function that takes an array and sorts the values.
*/

#include <iostream>

// Function to merge two subarrays
void Merge(int arr[], int left, int mid, int right) {
    int num1 = mid - left + 1;
    int num2 = right - mid;

    // Dynamically allocate memory for temporary arrays
    int* L = new int[num1];
    int* R = new int[num2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < num1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < num2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < num1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < num2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Deallocate memory for temporary arrays
    delete[] L;
    delete[] R;
}

// Function to implement merge sort
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        Merge(arr, left, mid, right);
    }
}

// Function to print an array
void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Hard-coded array with 10 elements - can update for user input array
    int arr[10] = { 12, 69, 1313, 5, 1, 4, 20, 15, 9, 888 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The unsorted array is: ";
    PrintArray(arr, arrSize);

    // Perform merge sort
    MergeSort(arr, 0, arrSize - 1);

    std::cout << "Sorted array is: ";
    PrintArray(arr, arrSize);

    return 0;
}




