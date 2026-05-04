#include <stdio.h>

void countingSort(int arr[], int n) {
    int max = arr[0];

    // Step 1: Find max element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    
    // Step 2: Initialize count array
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Step 3: Store frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];

    // Step 5: Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
