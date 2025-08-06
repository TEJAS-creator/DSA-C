#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Pointers to front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void Enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("%d enqueued to queue\n", x);
}

// Dequeue operation
void Dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// Print queue
void PrintQueue() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
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
