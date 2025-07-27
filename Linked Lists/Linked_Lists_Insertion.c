#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // Global head pointer

void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head; // Point temp to the current head
    head = temp;       // Update head to the temp
} // temp value is in head now


void Print() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL; // Initialize empty list

    int n, x;
    printf("Enter how many numbers you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}
