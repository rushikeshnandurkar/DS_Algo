#include<stdio.h>

// swaps two numbers, given their addresses.
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void selectionSort(int arr[], int num_of_elements)
{
    int i, j, min_idx;

    // in every iteration, ith element is deicided.
    for (i = 0; i < num_of_elements-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < num_of_elements; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&arr[i], &arr[min_idx]);
    }
}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");    
}

int main() 
{
    // taking usorted array as an input from keyboard
    int num_of_elements;
    scanf("%d", &num_of_elements);

    int arr[num_of_elements];
    for (int i = 0; i < num_of_elements; i++)
    {
        scanf("%d", &arr[i]);
    }

    // sorting the array using selectionSort function.
    selectionSort(arr, num_of_elements);

    // printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, num_of_elements);
    return 0;
}