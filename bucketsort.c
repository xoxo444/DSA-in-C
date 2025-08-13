#include <stdio.h>
#include <stdlib.h>

#define N 10  // Number of elements
#define BUCKETS 10 // Number of buckets

// Node structure for bucket linked list
struct Node {
    float data;
    struct Node* next;
};

// Insert element into bucket in sorted order
void insertSorted(struct Node** bucket, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL || (*bucket)->data >= value) {
        newNode->next = *bucket;
        *bucket = newNode;
    } else {
        struct Node* current = *bucket;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Bucket sort function
void bucketSort(float arr[], int n) {
    struct Node* buckets[BUCKETS] = {NULL};

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * BUCKETS; // index = value * bucket count
        insertSorted(&buckets[bucketIndex], arr[i]);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

int main() {
    float arr[N] = {0.78, 0.17, 0.39, 0.26, 0.72,
                    0.94, 0.21, 0.12, 0.23, 0.68};

    printf("Original array: ");
    for (int i = 0; i < N; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    bucketSort(arr, N);

    printf("Sorted array:   ");
    for (int i = 0; i < N; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
