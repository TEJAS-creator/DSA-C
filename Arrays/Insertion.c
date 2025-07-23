#include <stdio.h>

int insert(int arr[], int n, int pos, int value) {
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    return n + 1;  // Return the new size
}

void traverse(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

    n = insert(arr, n, 2, 99);  // Insert 99 at position 2

    traverse(arr, n);

    return 0;
}
