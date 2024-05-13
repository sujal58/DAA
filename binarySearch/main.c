#include <stdio.h>

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(array) / sizeof(array[0]);
    int num;
    printf("Enter a number to be Search:");
    scanf("%d", &num);
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == num)
        {
            printf("Element found at index %d\n", mid);
            return 0; // Exit the program as the element is found
        }

        if (array[mid] < num)
        {
            left = mid + 1; // Narrow the search to the right half
        }
        else
        {
            right = mid - 1; // Narrow the search to the left half
        }
    }

    printf("Element not found in the array\n");
    return 0;
}