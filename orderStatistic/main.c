#include<stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(arr[i] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i;
}

int quickSelect(int arr[], int low, int high, int k){
    if(low <= high){
        int pivotIndex = partition(arr, low, high);
        if(pivotIndex = k){
            return arr[pivotIndex];
        }else if(pivotIndex > k){
            return quickSelect(arr, low, pivotIndex-1, k);
        }else{
            return quickSelect(arr, pivotIndex+1, high, k);
        }
    }
    return 1;
}

float findMedian(int arr[], int n){
    if(n % 2 == 1){
        return quickSelect(arr, 0, n-1, n/2);
    }

    return (quickSelect(arr, 0, n-1, n/2-1) + quickSelect(arr, 0, n-1, n/2))/2;
}

int find_Kth_smallest(int arr[], int n , int k){
    if( k < 1 || k > n){
        printf("K is out of bounds of the array\n");
        return 1;
    }

    return quickSelect(arr, 0, n-1, k-1);
}

int main(){
    int arr[] = {12, 3, 2, 17, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    printf("Enter the position:");
    scanf("%d", &k);
    int result = find_Kth_smallest(arr, n, k);

    if(result != 1){
        printf("The %dth smallest element is %d\n", k , result);
    }

    printf("Median:%1f\n", findMedian(arr,n));
    return 0;
}