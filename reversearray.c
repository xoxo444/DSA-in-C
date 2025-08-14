#include <stdio.h>

void reverse(int arr[], int n) {
    int i = 0, j = n-1, temp;
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++; j--;
    }
}


int main() {
    int arr[] = {1,2,3,4,5}, n = 5;
    reverse(arr, n);
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}
