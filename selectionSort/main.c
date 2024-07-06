#include <stdio.h>

int main(void)
{
    int array[] = {14, 33, 27, 10, 35, 5};

    int size = sizeof(array) / sizeof(int);

    printf("\n UnShorted Array is : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[min_index] > array[j])
            {
                min_index = j;
            }
        }

        if (array[min_index] != array[i])
        {
            int temp;
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }

    printf("\n Shorted Array is : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}
