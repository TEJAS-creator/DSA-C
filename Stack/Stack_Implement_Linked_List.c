// top of Linked List head is going to be pushed or popped
// O(1) constant time operation

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL; // empty stack

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next=top;
    top=temp;
}

void Pop(){
    struct Node* temp;
    if(top == NULL){
      printf("Stack is empty");
      return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void Print() {
    struct Node* temp = top;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Push(2); Print();
    Push(3); Print();
    Push(4); Print();
    Push(5); Print();
    Push(6); Print();

    Pop(); Print();  // just call Pop() — it doesn’t take arguments
    Pop(); Print();

    Push(12); Print();
}
