#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3-way partition Quickselect
int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    int low = 0, high = numsSize - 1;

    while (low <= high) {
        // random pivot
        int pivotIndex = low + rand() % (high - low + 1);
        int pivot = nums[pivotIndex];

        // 3-way partition
        int lt = low, i = low, gt = high;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[i], &nums[lt]);
                i++; lt++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        // Now:
        // [low ... lt-1] < pivot
        // [lt ... gt] == pivot
        // [gt+1 ... high] > pivot

        if (target >= lt && target <= gt) {
            return pivot;  // found
        } else if (target < lt) {
            high = lt - 1;
        } else {
            low = gt + 1;
        }
    }

    return -1;
}
