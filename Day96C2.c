#include <stdio.h>
#include <stdlib.h>

int merge(int nums[], int left, int mid, int right) {
    int count = 0;

    // Count reverse pairs
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge step
    int temp[right - left + 1];
    int i = left, k = 0;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Copy back
    for (i = left, k = 0; i <= right; i++, k++)
        nums[i] = temp[k];

    return count;
}

int mergeSort(int nums[], int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    int count = 0;

    count += mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);

    return count;
}

// LeetCode function
int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}