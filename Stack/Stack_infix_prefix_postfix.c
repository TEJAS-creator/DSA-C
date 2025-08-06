// infix to postfix
// Scan the infix expression from left to right.
// If operand → Add to output.
// If ‘(’ → Push to stack.
// If ‘)’ → Pop until ‘(’ is found.
// If operator:
    // Pop from stack to output if the precedence of current operator ≤ stack top.
    // Then push current operator to stack.
// After complete scan, pop remaining operators from stack to output.



// infix expression reverse
// swap ( and )
// now infix to postfix the expression
// reverse it


// CODE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Reverse a string
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
}

// Infix to Postfix
void infixToPostfix(char* infix, char* postfix) {
    top = -1;
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // pop '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Infix to Prefix
void infixToPrefix(char* infix, char* prefix) {
    top = -1;
    char revInfix[MAX], revPostfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < strlen(revInfix); i++) {
        if (revInfix[i] == '(') revInfix[i] = ')';
        else if (revInfix[i] == ')') revInfix[i] = '(';
    }

    infixToPostfix(revInfix, revPostfix);
    reverse(revPostfix);

    strcpy(prefix, revPostfix);
}

// Menu
int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int choice;

    printf("Enter an Infix Expression: ");
    scanf("%s", infix);

    do {
        printf("\n----- Menu -----\n");
        printf("1. Convert to Postfix\n");
        printf("2. Convert to Prefix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;
            case 2:
                infixToPrefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
