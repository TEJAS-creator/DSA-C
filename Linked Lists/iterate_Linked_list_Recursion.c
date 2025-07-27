#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Recursive function to insert at end
struct Node* InsertRecursive(struct Node* head, int data) {
    if (head == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    head->next = InsertRecursive(head->next, data);
    return head;
}

// Recursive function to print the list
void PrintRecursive(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    // printf("%d ", head->data); // prints in normal order
    PrintRecursive(head->next);
    printf("%d ", head->data); // prints in recursive order

}

int main() {
    struct Node* head = NULL;

    head = InsertRecursive(head, 10);
    head = InsertRecursive(head, 20);
    head = InsertRecursive(head, 30);
    head = InsertRecursive(head, 40);

    printf("Linked List: ");
    PrintRecursive(head);  // Output: 10 → 20 → 30 → 40 → NULL

    return 0;
}
