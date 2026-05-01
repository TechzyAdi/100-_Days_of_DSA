int canSplit(int* nums, int n, int k, int maxSum) {
    int count = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + nums[i] <= maxSum) {
            current += nums[i];
        } else {
            count++;
            current = nums[i];

            if (count > k)
                return 0;
        }
    }

    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int left = 0, right = 0;

    // find max and sum
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > left)
            left = nums[i];

        right += nums[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;        // possible
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // increase
        }
    }

    return ans;
}
