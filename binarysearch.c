#include <stdio.h>

int binarysearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key, i;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to find: ");
    scanf("%d", &key);

    int result = binarysearch(arr, n, key);

    if (result == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", result);

    return 0;
}
