#include <stdio.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i]);
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int main(void)
{
    int arr[] = {5, 1, 6, 2, 4, 3};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("\n After sorting: ");
    printArray(arr, size);
}
