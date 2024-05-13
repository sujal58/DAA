#include <stdio.h>
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    // printf("Swapped Elelemnt is %d & %d", *a, *b);
}

int partition(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low;

    for(int j = low+1; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            // printf("\n %d is smaller than pivot element %d\n ", arr[j], pivot);
            swap(&arr[i], &arr[j]);
            // printf("\n %d is found to be smaller than %d so swapping is done between them.\n", arr[i], arr[j]);
            // printf("\n value of i and j are %d and %d \n", i, j);
        }
    }
    // printf("\n Index of pivot is found at: %d \n", i);
    swap(&arr[low], &arr[i]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if(low < high){

        int index = partition(arr, 0, high);
        // printf("\nDividing Array from :[%d to %d]\n", arr[low], arr[index-1]);
        quickSort(arr, low, index-1);
        // printf("\nDividing Array from :[%d to %d]\n", arr[index+1], arr[high]);
        quickSort(arr, index+1, high);
    }
}

int main(void)
{
    int arr[] = {5, 1, 6, 2, 4, 3};

    int size = sizeof(arr)/sizeof(arr[0]);

     printf("Before sorting: ");
    printArray(arr, size);

   quickSort(arr, 0, size-1);

    // printf("\n %d", i);
    printf("\n After sorting: ");
    printArray(arr, size);

}
