#include<stdio.h>

// swaps two numbers, given their addresses.
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void insertionSort(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // sorting the array using insertionSort function.
    insertionSort(arr, num_of_elements);

    // printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, num_of_elements);
    return 0;
}