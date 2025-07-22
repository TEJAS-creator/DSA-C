#include <stdio.h>

// O(1) - Constant Time
void constantTime(int arr[]) {
    printf("O(1) Example:\n");
    printf("First element: %d\n", arr[0]);
}

// O(n) - Linear Time
void linearTime(int arr[], int size) {
    printf("\nO(n) Example:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// O(n^2) - Quadratic Time (Nested Loops)
void quadraticTime(int arr[], int size) {
    printf("\nO(n^2) Example:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i] * arr[j]);
        }
    }
    printf("\n");
}

// O(log n) - Logarithmic Time (Binary Search)
int binarySearch(int arr[], int low, int high, int target) {
    printf("\nO(log n) Example: Binary Search\n");
    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("Checking index: %d\n", mid);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// O(2^n) - Exponential Time (Recursive Fibonacci)
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// O(n!) - Factorial Time (Example: Permutations count)
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    // O(1) example
    constantTime(arr);

    // O(n) example
    linearTime(arr, size);

    // O(n^2) example
    quadraticTime(arr, size);

    // O(log n) example (Binary Search)
    int target = 30;
    int index = binarySearch(arr, 0, size - 1, target);
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);

    // O(2^n) example (Fibonacci)
    int fib_n = 5;
    printf("\nO(2^n) Example: Fibonacci of %d is %d\n", fib_n, fibonacci(fib_n));

    // O(n!) example (Factorial)
    int fact_n = 5;
    printf("\nO(n!) Example: Factorial of %d is %d\n", fact_n, factorial(fact_n));

    return 0;
}


// OUTPUT

// O(1) Example:
// First element: 10

// O(n) Example:
// 10 20 30 40 50 

// O(n^2) Example:
// 100 200 300 400 500 ... (25 numbers)

// O(log n) Example: Binary Search
// Checking index: 2
// Element 30 found at index 2

// O(2^n) Example: Fibonacci of 5 is 5

// O(n!) Example: Factorial of 5 is 120
