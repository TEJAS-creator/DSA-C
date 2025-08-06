// BALANCED PARANTHESIS
// A string has balanced parentheses if:
// Every opening bracket has a corresponding closing bracket in the correct order.
// The brackets are properly nested.

// 99 is the maximum safe index (stack size - 1).
// 0 is just a placeholder (no-op) when the condition fails (i.e., stack overflow).
// ternary operators are used =  ? :
// If you get ), it checks if the top of the stack was ( → if not → mismatch
// Same for ] and }
// top = -999; → Marks that an error occurred (custom error flag)
// i = strlen(s); → Sets i to the length of the string, which forces the loop to end



#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1; // empty stack

void push(char ch) { top < 99 ? stack[++top] = ch : 0; }

char pop() { return top >= 0 ? stack[top--] : '\0'; }

int isBalanced(char *s) {
    for (int i = 0; s[i]; i++)
        (s[i] == '(' || s[i] == '[' || s[i] == '{') ? push(s[i]) :
        (s[i] == ')' && pop() != '(') ||
        (s[i] == ']' && pop() != '[') ||
        (s[i] == '}' && pop() != '{') ?
        (top = -999, i = strlen(s)) : 0;

    return top == -1; // empty stack
}

int main() {
    char str[100];
    printf("Enter expression: ");
    fgets(str, sizeof(str), stdin);

    printf(isBalanced(str) ? "Balanced" : "Not Balanced");
    return 0;
}
