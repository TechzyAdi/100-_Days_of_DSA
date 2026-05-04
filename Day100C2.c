#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int val;
    int index;
};

void merge(struct Pair arr[], int left, int mid, int right, int* counts) {
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;
    struct Pair temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++; // smaller element from right
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // copy back
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(struct Pair arr[], int left, int right, int* counts) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);
    merge(arr, left, mid, right, counts);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    struct Pair arr[numsSize];
    int* counts = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, counts);

    *returnSize = numsSize;
    return counts;
}