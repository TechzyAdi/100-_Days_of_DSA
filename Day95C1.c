#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order (Insertion Sort logic)
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning or before head
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    struct Node* buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
