#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data, int n) {
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        if (temp2 == NULL) {
            printf("Invalid position %d\n", n);
            return;
        }
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete(int n) {
    struct Node* temp1 = head;

    if (n == 1) {
        if (head == NULL) {
            printf("List is empty.\n");
            return;
        }
        head = head->next;
        free(temp1);
        return;
    }

    for (int i = 0; i < n - 2; i++) {
        if (temp1 == NULL || temp1->next == NULL) {
            printf("Invalid position %d\n", n);
            return;
        }
        temp1 = temp1->next;
    }

    struct Node* temp2 = temp1->next;
    if (temp2 == NULL) {
        printf("Invalid position %d\n", n);
        return;
    }

    temp1->next = temp2->next;
    free(temp2);
}

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
    head = NULL; // initialize empty list

    Insert(5, 1); // List: 5
    Insert(6, 2); // List: 5 6
    Insert(7, 3); // List: 5 6 7
    Insert(8, 4); // List: 5 6 7 8
    Print();

    int n;
    printf("Enter the position to delete: ");
    scanf("%d", &n);

    Delete(n);
    Print();

    return 0;
}
