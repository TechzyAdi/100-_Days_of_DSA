int canShip(int* weights, int n, int days, int capacity) {
    int usedDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (currentLoad + weights[i] <= capacity) {
            currentLoad += weights[i];
        } else {
            usedDays++;
            currentLoad = weights[i];

            if (usedDays > days)
                return 0;
        }
    }

    return 1;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int left = 0, right = 0;

    // find max and sum
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > left)
            left = weights[i];   // max element

        right += weights[i];     // sum
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            ans = mid;        // possible
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // increase capacity
        }
    }

    return ans;
}
