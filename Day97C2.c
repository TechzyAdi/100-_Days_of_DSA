#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minRooms(int start[], int end[], int n) {

    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n && j < n) {

        if (start[i] < end[j]) {
            rooms++;  // need new room
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        }
        else {
            rooms--;  // room freed
            j++;
        }
    }

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++) scanf("%d", &start[i]);
    for (int i = 0; i < n; i++) scanf("%d", &end[i]);

    printf("%d\n", minRooms(start, end, n));

    return 0;
}