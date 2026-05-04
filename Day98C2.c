#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {
    
    // Step 1: Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int index = 0;

    // Initialize with first interval
    result[index] = (int*)malloc(sizeof(int) * 2);
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];
    (*returnColumnSizes)[index] = 2;
    index++;

    // Step 2: Merge intervals
    for (int i = 1; i < intervalsSize; i++) {
        int lastStart = result[index - 1][0];
        int lastEnd = result[index - 1][1];

        if (intervals[i][0] <= lastEnd) {
            // Merge
            if (intervals[i][1] > lastEnd)
                result[index - 1][1] = intervals[i][1];
        } else {
            // New interval
            result[index] = (int*)malloc(sizeof(int) * 2);
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
            index++;
        }
    }

    *returnSize = index;
    return result;
}