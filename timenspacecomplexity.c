#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   
    }
    return -1; 
}


int main() {
    int n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

  
    int index = linearSearch(arr, n, key);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("\nTime Complexity Analysis:\n");
    printf("Best Case  : O(1)  (element at first position)\n");
    printf("Worst Case : O(n)  (element at last position or not present)\n");
    printf("Average    : O(n)\n");

    printf("\nSpace Complexity Analysis:\n");
    printf("Input Array: O(n)\n");
    printf("Variables  : O(1)\n");
    printf("Total      : O(n)\n");

    return 0;
}
