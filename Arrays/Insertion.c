#include <stdio.h>

void insert(int arr[], int size, int pos, int value) {
    for(int i = size; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

    insert(arr, n, 2, 99); // Insert 99 at index 2
    n++; // Increase array size manually

    traverse(arr, n);

    return 0;
}
