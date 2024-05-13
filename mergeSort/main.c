
#include <stdio.h>

void merge(int arr[],int l,int m,int r){

    printf("merging: ");
    for (int i = 0; i <= r-l; ++i) {
        printf("%d \t", arr[i]);
    }
    printf("\n");

    int n1 = m-l+1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[l+i];
    }

    for (int i = 0; i < n2; ++i) {
        R[i] = arr[m+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j <  n2) {
        if(L[i] >= R[j]) {
            arr[k] = L[i++];
        }else {
            arr[k] = R[j++];
        }
        k++;
    }

    while(i < n1) {
        arr[k++]=L[i++];
    }

    while(j < n2) {
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {

    printf("Dividing: ");
    for (int i = 0; i <= r-l; ++i) {
        printf("%d \t", arr[i]);
    }
    printf("\n");
    if(l < r) {
        int m = l + (r - l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }

    printf("\n");

}
int main(void) {
    int arr[]={1,3,5,7,2,4,6,9,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array\n");
    printArray(arr, n);

    mergeSort(arr, 0,n-1);

    printf("sorted descending Array\n");
    printArray(arr, n);
    return 0;
}