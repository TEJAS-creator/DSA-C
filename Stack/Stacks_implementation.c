// Array implmentation
// Time complexity = O(1) = constant time
// time taken to copy elements from one array to another = O(n)

// array implementation of stack

#include <stdio.h>
#define MAX_SIZE 100

int a[MAX_SIZE];
int top = -1; // empty stack

void Push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    a[++top] = x;
}

void Pop() {
    if (top == -1) {
        printf("Error: No element is present to pop\n");
        return;
    }
    top--;
}

int Top() { // returns the element at top of stack
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return a[top];
}

void Print() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    Push(2); Print();
    Push(3); Print();
    Push(4); Print();
    Push(5); Print();
    Push(6); Print();

    Pop(); Print();  // just call Pop() — it doesn’t take arguments
    Pop(); Print();

    Push(12); Print();

    printf("Element at top is: %d\n", Top());

    return 0;
}












