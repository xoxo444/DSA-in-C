#include <stdio.h>

int main() {
    int n, target, i;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to find: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Found at index %d\n", i);
            return 0;
        }
    }

    printf("Not found\n");
    return 0;
}
