// Reversing a string using stack
// time complexity = O(n)
// space complexity = O(n)

#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    char stack[len];
    int top = -1;

    // Push each character onto the stack
    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    // Pop characters back to the string
    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    reverseString(str);
    printf("Reversed string: %s", &str);

    return 0;
}
