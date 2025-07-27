#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data, int n) {
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));  // correct in C
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
            printf("Position %d is invalid.\n", n);
            return;
        }
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
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
    head = NULL;
    Insert(2, 1);  // 2
    Insert(4, 2);  // 2 -> 4
    Insert(6, 3);  // 2 -> 4 -> 6
    Insert(8, 2);  // 2 -> 8 -> 4 -> 6
    Print();
    return 0;
}
