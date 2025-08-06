// insertion at rear or tail end
// deletion at front or head end
// -----------------------------------------
// enque=> rear |        | front dequeue=>
// -----------------------------------------

// operations
// enqueue - insertion
// dequeue - deletion
// front - top of the queue
// isEmpty - empty or not
// Overflow: When rear == SIZE - 1 (no space to add).
// Underflow: When front == -1 (no element to remove).


#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int a[SIZE];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Enqueue operation
void Enqueue(int x) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", x);
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    a[rear] = x;
    printf("%d added to queue\n", x);
}

// Dequeue operation
void Dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    } else if (front == rear) {
        printf("Removed element: %d\n", a[front]);
        front = rear = -1; // queue becomes empty
    } else {
        printf("Removed element: %d\n", a[front]);
        front++;
    }
}

// Print queue
void PrintQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                PrintQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
