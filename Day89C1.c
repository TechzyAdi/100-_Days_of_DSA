#include <stdio.h>

// Check if allocation is possible with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages of books:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = 0;

    // right = sum of all pages
    for (int i = 0; i < n; i++) {
        right += arr[i];
    }

    int ans = right;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;        // possible answer
            right = mid - 1;  // try smaller
        } else {
            left = mid + 1;   // increase limit
        }
    }

    printf("Minimum maximum pages: %d\n", ans);

    return 0;
}
