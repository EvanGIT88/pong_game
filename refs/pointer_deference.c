#include <stdio.h>

int main()
{
    int a = 5, b = 6;

    // Pointer declared
    int *pt;

    // Referencing
    pt = &a;

    printf("The address where a is stored is: %p\n", (void *)pt);
    printf("The value stored at the address by dereferencing the pointer is: %d\n", *pt);

    // Changing value of variable Address stored in the pointer will not be affected by this
    *pt = b;

    printf("Pointer is still pointing at: %p\n", (void *)pt);
    printf("The new value stored at the address by dereferencing the pointer is: %d\n", *pt);
    printf("Now the value of a is: %d\n", a);

    getchar();
    return 0;
}