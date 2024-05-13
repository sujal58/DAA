#include <stdio.h>

int main(void) {

    int number[] = {14, 33, 27, 10, 35,5,2};
    int size = sizeof(number)/sizeof(int);

    printf("Unsorted array is: \n");
    for (int i = 0; i <= size-1; i++) {
        printf("%d \t", number[i]);
    }

    for(int i = 0; i< size-1; i++) {
        for(int j =0; j < size-1-i; j++) {
            if(number[j] > number[j+1]) {
                int temp;
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            };
        }
    }

    printf("\n\nSorted array is: \n");
    for (int i = 0; i <= size-1; i++) {
        printf("%d \t", number[i]);
    }

    return 0;
}
