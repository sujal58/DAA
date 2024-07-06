#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void printSort(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void heapify(int arr[], int size, int curr)
{
    int leftchild = 2 * curr + 1;
    int rightchild = 2 * curr + 2;
    int smallest = curr;

    if (leftchild <= size && arr[leftchild] < arr[smallest])
    {
        smallest = leftchild;
    }

    if (rightchild <= size && arr[rightchild] < arr[smallest])
    {
        smallest = rightchild;
    }

    if (smallest != curr)
    {
        swap(&arr[smallest], &arr[curr]);
        heapify(arr, size, smallest);
    }
}

void heapSort(int arr[], int size)
{

    for (int i = size / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int j = 0; j < size; j++)
    {
        swap(&arr[0], &arr[size - j]);
        heapify(arr, size - j - 1, 0);
    }
}

int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array is:\t");
    printSort(arr, n - 1);
    heapSort(arr, n - 1);
    printf("\n\nSorted Heap tree is:\t");
    printSort(arr, n - 1);
}