#include <stdio.h>

// Check if painting is possible within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        // If single board exceeds maxTime → impossible
        if (boards[i] > maxTime)
            return 0;

        if (current + boards[i] <= maxTime) {
            current += boards[i];
        } else {
            painters++;
            current = boards[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int left = 0, right = 0;

    // find max and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > left)
            left = boards[i];

        right += boards[i];
    }

    int ans = right;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;        // possible
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // increase time
        }
    }

    printf("Minimum time required: %d\n", ans);

    return 0;
}
