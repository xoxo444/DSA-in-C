#include <stdio.h>

// Function to calculate next gap
int getNextGap(int gap) {
    // Shrink gap by shrink factor 1.3
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

// Comb Sort function
void combSort(int arr[], int n) {
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped) {
        // Update the gap
        gap = getNextGap(gap);
        swapped = 0;

        // Compare elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                // Swap arr[i] and arr[i+gap]
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                swapped = 1;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    combSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
