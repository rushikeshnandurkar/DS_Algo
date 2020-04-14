#include <stdio.h>
#include <stdlib.h>

void myFun()
{
    // creating dynamic array with calloc
    int *ptr;
    int size;
    printf("Enter a size: ");
    scanf("%d", &size);

    // using calloc for creating array of length - size
    ptr = (int *)calloc(size, sizeof(int));

    // scanning values using indexing
    int *p = ptr;
    for (int i = 0; i < size; i++, p++)
    {
        scanf("%d", &ptr[i]);
    }

    // we can access the dynamic array by both * (value of) operator
    // and indexing as in normal arrays
    printf("Values Accessed By :-\n");
    printf("* operator\tIndexing\n");
    p = ptr;
    for (int i = 0; i < size; i++, p++)
    {
        printf("%d\t\t%d\n", *p, ptr[i]);
    }
    
}

int main()
{
    myFun();
    return 0;
}