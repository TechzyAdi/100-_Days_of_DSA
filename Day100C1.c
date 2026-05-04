#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int value, index;
};

// Merge function
void merge(struct Pair arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    struct Pair temp[100];
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;  // smaller element from right
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge sort
void mergeSort(struct Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

// Main
int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    struct Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    printf("Counts: ");
    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}
