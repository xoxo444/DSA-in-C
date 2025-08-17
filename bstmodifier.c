#include <stdio.h>


// f(x) for binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

  
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; 
}


int main() {
    int n, key, pos, newValue;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);

  
    if (pos == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element %d found at position %d.\n", key, pos);

        printf("Enter new value to modify: ");
        scanf("%d", &newValue);

        arr[pos] = newValue; // modify data
        printf("Value updated!\n");

        printf("Updated array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
