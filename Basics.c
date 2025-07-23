#include <stdio.h>

int main() {
    // Entry point of the program.
    printf("Hello, World!\n"); // Basic output statement.
    return 0; // Indicate that program ended successfully.
}


#include <stdio.h>

int main() {
    // Declaration and initialization of variables
    int integerVar = 10;          // Integer type
    float floatVar = 3.14f;       // Floating-point type
    double doubleVar = 123.456;   // Double precision floating-point
    char charVar = 'A';           // Character type

    // Output the variables
    printf("Integer: %d\n", integerVar);
    printf("Float: %f\n", floatVar);
    printf("Double: %lf\n", doubleVar);
    printf("Character: %c\n", charVar);

    return 0;
}


#include <stdio.h>

int main() {
    int number;
    char text[50];

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &number); // Read integer input

    // Consume any leftover newline character before reading a string
    getchar();
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin); // Read a string (including spaces)
    
    // Display the input values
    printf("You entered integer: %d\n", number);
    printf("You entered string: %s\n", text);

    return 0;
}


#include <stdio.h>

int main() {
    int a = 8, b = 3;

    // Arithmetic Operators
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %d\n", a / b);
    printf("Modulus: %d\n", a % b);

    // Relational Operators
    printf("Is a greater than b? %d\n", a > b);   // prints 1 for true
    printf("Is a equal to b? %d\n", a == b);

    // Logical Operators
    printf("Logical AND (a > 5 and b < 5): %d\n", (a > 5 && b < 5));
    printf("Logical OR  (a < 5 or b < 5): %d\n", (a < 5 || b < 5));

    return 0;
}



#include <stdio.h>

int main() {
    int a = 8, b = 3;

    // Arithmetic Operators
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %d\n", a / b);
    printf("Modulus: %d\n", a % b);

    // Relational Operators
    printf("Is a greater than b? %d\n", a > b);   // prints 1 for true
    printf("Is a equal to b? %d\n", a == b);

    // Logical Operators
    printf("Logical AND (a > 5 and b < 5): %d\n", (a > 5 && b < 5));
    printf("Logical OR  (a < 5 or b < 5): %d\n", (a < 5 || b < 5));

    return 0;
}




#include <stdio.h>

// Function prototype
int add(int a, int b);

int main() {
    int num1 = 5, num2 = 7;
    int sum = add(num1, num2); // Function call
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}



#include <stdio.h>
#include <string.h>

int main() {
    // Declaration of a string (character array)
    char str1[] = "Hello, C Language!";
    char str2[50];

    // Copying string using strcpy
    strcpy(str2, str1);

    // Concatenating a string using strcat
    strcat(str2, " Enjoy learning!");

    // Output the resulting string
    printf("Resulting String: %s\n", str2);
    return 0;
}




#include <stdio.h>

int main() {
    int value = 100;
    int *pointer = &value; // Pointer holds address of variable 'value'
    
    // Printing the value using the pointer
    printf("Value: %d\n", value);
    printf("Value via pointer: %d\n", *pointer);
    
    // Printing the address stored in the pointer
    printf("Address of value: %p\n", (void*)pointer);
    return 0;
}




#include <stdio.h>
#include <string.h>

// Structure definition
struct Person {
    char name[50];
    int age;
};

// Union definition
union Data {
    int intValue;
    float floatValue;
};

int main() {
    // Working with a structure
    struct Person person1;
    strcpy(person1.name, "Tejas");
    person1.age = 22;
    printf("Structure - Name: %s, Age: %d\n", person1.name, person1.age);

    // Working with a union
    union Data data;
    data.intValue = 100;
    printf("Union as integer: %d\n", data.intValue);
    
    // Assigning a float will overwrite the integer value in union
    data.floatValue = 98.76f;
    printf("Union as float: %f\n", data.floatValue);
    
    return 0;
}




