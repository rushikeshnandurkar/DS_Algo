// basic principal is that if p and q do not cross each other
// we swap elements at p and q
// and if they cross... we swap pivot element with qth element

#include <stdio.h>

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    high++; // bcoz otherwise last location is always skipped
    int lower = low;
    while (low < high)
    {
        do
        {
            low++;
        } while (arr[low] < pivot); // low index stops where number greater than pivot is encountered
        do
        {
            high--;
        } while (arr[high] > pivot); // high index stops where number lower than pivot is encountered

        if (low < high)
            swap(&arr[low], &arr[high]);
    }
    swap(&arr[high], &arr[lower]);
    return high;
}

void quick(int arr[], int low, int high)
{
    if (low < high)
    {
        int m = partition(arr, low, high);
        quick(arr, low, m);
        quick(arr, m + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
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

    // sorting the array using bubblesort function.
    quick(arr, 0, num_of_elements - 1);

    // printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, num_of_elements);
    return 0;
}
