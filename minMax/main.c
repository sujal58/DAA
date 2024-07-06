#include <stdio.h>

struct maxMin {
    int min;
    int max;
};

struct maxMin minmax(int arr[], int low, int high) {
    struct maxMin left;
    struct maxMin right;
    struct maxMin result;
    int mid;

    if(low == high) {
        result.min = arr[low];
        result.max = arr[high];
        return result;
    }

    if(high == low + 1) {
        if(arr[low]<arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        }else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    mid = low + (high - low)/2;

    left = minmax(arr, 0,mid);
    right = minmax(arr, mid+1, high);


    if(left.min < right.min) {
        result.min = left.min;
    }else {
        result.min = right.min;
    }

    if(left.max > right.max) {
        result.max = left.max;
    }else {
        result.max = right.max;
    }

    return result;
}


 int main(void)
{
    int arr[] = {2,4,8,1,3,9,22,35};
     int size = sizeof(arr)/sizeof(arr[0]);
    struct maxMin result = minmax(arr, 0, 1);
    printf("Min value:%d\n", result.min);
    printf("Max value:%d", result.max);
}
