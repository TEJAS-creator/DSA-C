#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; // pointer to head node

// Create a new node
struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// Print the linked list
void Print() {
    struct Node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Print in reverse
void ReversePrint() {
    struct Node* temp = head;
    if (temp == NULL) return;

    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward
    printf("List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    InsertAtHead(2);    Print(); ReversePrint();
    InsertAtHead(4);    Print(); ReversePrint();
    InsertAtHead(6);    Print(); ReversePrint();
    InsertAtHead(8);    Print(); ReversePrint();
    InsertAtHead(10);   Print(); ReversePrint();
    return 0;
}
