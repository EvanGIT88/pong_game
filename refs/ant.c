// C program to demonstrate that we can change
// local values of one function in another using pointers.

#include <stdio.h>

/*
*y can  only be assigned to pointer var object (ex: *x) and value correspond to its data type on initialization
y can only be assigned to normal var address and malloc and new value correspond to its data type
*/

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("%d %d\n", x, y);
    getchar()
    return 0;
}