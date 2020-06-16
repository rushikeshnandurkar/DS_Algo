#include<stdio.h>

// swaps two numbers, given their addresses.
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


// function to sort the given array in ascending order using bubble sort.
// num = num of elements in array
void bubbleSort(int arr[], int num) 
{
    int i, j;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
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
    // taking unsorted array as an input from keyboard
    int num_of_elements;
    scanf("%d", &num_of_elements);

    int arr[num_of_elements];
    for (int i = 0; i < num_of_elements; i++)
    {
        scanf("%d", &arr[i]);
    }

    // sorting the array using bubblesort function.
    bubbleSort(arr, num_of_elements);

    // printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, num_of_elements);
    return 0;
}
