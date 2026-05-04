#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting {
    int start, end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;
    return m1->start - m2->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

// Remove min (root)
void removeMin(int heap[], int *size) {
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(struct Meeting arr[], int n) {
    // Step 1: Sort meetings by start time
    qsort(arr, n, sizeof(struct Meeting), compare);

    int heap[100]; // min-heap for end times
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, arr[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If earliest meeting ends before current starts
        if (heap[0] <= arr[i].start) {
            removeMin(heap, &size); // reuse room
        }
        insertHeap(heap, &size, arr[i].end);
    }

    return size; // number of rooms
}

// Main
int main() {
    struct Meeting arr[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int rooms = minMeetingRooms(arr, n);

    printf("Minimum number of rooms required: %d\n", rooms);

    return 0;
}
