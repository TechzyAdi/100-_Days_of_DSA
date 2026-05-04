#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start, end;
};

// Compare function for sorting
int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

// Merge intervals
void mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval result[n];
    int index = 0;

    // Add first interval
    result[index++] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index - 1].end) {
            // Overlap → merge
            if (arr[i].end > result[index - 1].end)
                result[index - 1].end = arr[i].end;
        } else {
            // No overlap → add new interval
            result[index++] = arr[i];
        }
    }

    // Print result
    printf("Merged intervals:\n");
    for (int i = 0; i < index; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

// Main
int main() {
    struct Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
