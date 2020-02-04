#include <stdio.h>

void merge(int L[], int first, int mid, int last)
{
    int i, j, k, cnt;
    int temp[10];

    i = first;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= last)
    {
        if (L[i] < L[j])
        {
            temp[k] = L[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = L[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = L[i];
        i++;
        k++;
    }
    while (j <= last)
    {
        temp[k] = L[j];
        j++;
        k++;
    }

    for (cnt = 0; cnt < k; cnt++)
    {
        L[first + cnt] = temp[cnt];
    }
}

void mergeSort(int L[], int first, int last)
{
    if (last > first)
    {
        int mid;
        mid = (first + last) / 2;
        mergeSort(L, first, mid);
        mergeSort(L, mid + 1, last);
        merge(L, first, mid, last);
    }
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

    // sorting the array using mergeSort function.
    mergeSort(arr, 0, num_of_elements - 1);

    // printing the sorted array
    printf("Sorted Array:\n");
    printArray(arr, num_of_elements);
    return 0;
}