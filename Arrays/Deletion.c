#include <stdio.h>

void deleteAt(int arr[], int size, int pos) {
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

    deleteAt(arr, n, 2); // Delete at index 2
    n--; // Reduce size manually

    traverse(arr, n);

    return 0;
}
