#include <stdio.h>

int main(void) {
    int arr[] = {2,5,1,6,3,9};

    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\n Sorted Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}
