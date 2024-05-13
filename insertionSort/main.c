#include <stdio.h>

int main(void) {
    int arr[] = {2,5,1,6,3,9};

    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < size; i++) {
        int key = i;
        int j = i - 1;

        while(j >= 0 && arr[j] > arr[j+1]) {
            arr[j+1] = arr[j];
            j--;
        }
        

    }


    return 0;
}
