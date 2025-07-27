#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Sorted
    int n = 5, key = 40;

    int index = binarySearch(arr, n, key);

    if(index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found\n", key);

    return 0;
}
