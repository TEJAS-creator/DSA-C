#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key = 30;

    int index = linearSearch(arr, n, key);

    if(index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found\n", key);

    return 0;
}
