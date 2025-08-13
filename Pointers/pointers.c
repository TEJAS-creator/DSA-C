/*
int a // integer
int *p // pointer to integer
a = 5
p = &a
print p // address of a
print &a // address of a
print &p // address of p
print *p // given value pointed at a which is 5 (dereferencing)
*p = 8 // modify the value at which p is pointing meaning change the value of a
print a // prints 8 since the value changed in a
*/


/*
#include<stdio.h>
int main(){
    int a = 10;
    int *p;
    p=&a;
    printf("Value before dereferencing: %d",a);
    *p=8;
    printf("\nValue after dereferencing: %d",a);
    printf("\nAddress before increment: %d",p);
    p+1; // increments by 4
    printf("\nAddress after increment: %d",p);
}
*/

/*
// Pointer to Pointer
#include <stdio.h>

int main() {
    int x = 5;
    int *p;
    p = &x;
    *p = 2;

    int **q; // pointer to pointer
    q = &p;

    int ***r;
    r = &q;

    // Printing all values
    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    printf("**q = %d\n", **q);
    printf("***r = %d\n", ***r);

    // Printing addresses
    printf("&x = %p\n", (void*)&x);
    printf("p (address of x) = %p\n", *p);
    printf("*q (value of p) = %p\n", **q);
    printf("**r (value of *p) = %p\n", ***r); // address of x, but as int pointer
    printf("q (address of p) = %p\n", *q);
    printf("r (address of q) = %p\n", *r);

    return 0;
}
*/



/*
// Pointer as function
#include<stdio.h>
void increment(int *p){
    *p = (*p)+1;
}
int main(){
    int a;
    int *p;
    printf("Enter number: ");
    scanf("%d",&a);
    p = &a;
    increment(p);
    printf("Number: %d",a);
    return 0;
}

*/


// variable = (datatype*)malloc(sizeof(datatype))

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int)); // dynamically allocated array
    if (a == NULL) { // check if malloc failed
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a); // free allocated memory
    return 0;
}

