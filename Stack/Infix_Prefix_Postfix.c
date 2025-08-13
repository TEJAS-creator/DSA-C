#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int precedence(char ch) {
    switch(ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    char st[MAX], temp[2], ch;
    int topS = -1, k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            st[++topS] = ch;
        else if (ch == ')') {
            while (topS >= 0 && st[topS] != '(')
                postfix[k++] = st[topS--];
            topS--;
        } else {
            while (topS >= 0 && precedence(st[topS]) >= precedence(ch))
                postfix[k++] = st[topS--];
            st[++topS] = ch;
        }
    }
    while (topS >= 0)
        postfix[k++] = st[topS--];
    postfix[k] = '\0';
}

// Reverse a string
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char rev[MAX], post[MAX];
    strcpy(rev, infix);
    reverse(rev);
    for (int i = 0; i < strlen(rev); i++) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }
    infixToPostfix(rev, post);
    strcpy(prefix, post);
    reverse(prefix);
}

// Prefix to Postfix
void prefixToPostfix(char prefix[], char postfix[]) {
    top = -1;
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char op[2] = {prefix[i], '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(expr, "%s%s%c", op1, op2, prefix[i]);
            push(expr);
        }
    }
    strcpy(postfix, pop());
}

// Prefix to Infix
void prefixToInfix(char prefix[], char infix[]) {
    top = -1;
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char op[2] = {prefix[i], '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(expr, "(%s%c%s)", op1, prefix[i], op2);
            push(expr);
        }
    }
    strcpy(infix, pop());
}

// Postfix to Prefix
void postfixToPrefix(char postfix[], char prefix[]) {
    top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        if (isalnum(postfix[i])) {
            char op[2] = {postfix[i], '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(expr, "%c%s%s", postfix[i], op1, op2);
            push(expr);
        }
    }
    strcpy(prefix, pop());
}

// Postfix to Infix
void postfixToInfix(char postfix[], char infix[]) {
    top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        if (isalnum(postfix[i])) {
            char op[2] = {postfix[i], '\0'};
            push(op);
        } else {
            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(expr, "(%s%c%s)", op1, postfix[i], op2);
            push(expr);
        }
    }
    strcpy(infix, pop());
}

int main() {
    char exp[MAX], res[MAX];
    int choice;
    printf("Enter expression: ");
    scanf("%s", exp);
    printf("\n1. Infix to Prefix\n2. Infix to Postfix\n3. Prefix to Postfix\n4. Prefix to Infix\n5. Postfix to Prefix\n6. Postfix to Infix\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: infixToPrefix(exp, res); printf("Prefix: %s\n", res); break;
        case 2: infixToPostfix(exp, res); printf("Postfix: %s\n", res); break;
        case 3: prefixToPostfix(exp, res); printf("Postfix: %s\n", res); break;
        case 4: prefixToInfix(exp, res); printf("Infix: %s\n", res); break;
        case 5: postfixToPrefix(exp, res); printf("Prefix: %s\n", res); break;
        case 6: postfixToInfix(exp, res); printf("Infix: %s\n", res); break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}
