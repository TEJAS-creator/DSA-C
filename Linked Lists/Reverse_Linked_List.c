#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Insert at the beginning (for quick testing)
void Insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Print the linked list
void Print() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void Reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;     // Store next
        current->next = prev;     // Reverse current node's pointer
        prev = current;           // Move prev one step ahead
        current = next;           // Move current one step ahead
    }

    head = prev; // Update head to the new front
}

int main() {
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);  // List will be: 40 → 30 → 20 → 10

    printf("Original: ");
    Print();

    Reverse();

    printf("Reversed: ");
    Print();

    return 0;
}




// -----------LOGIC---------
// next = current->next;
// current->next = prev;
// prev = current;
// current = next;
