#include <stdio.h>

int main(void)
{
    int list[] = {2, 3, 4, 5, 6, 12, 18, 25, 19};
    int n, found = 0, i;

    printf("Enter a number to be searched:");
    scanf("%d", &n);

    for (i = 0; i < 9; i++)
    {
        if (list[i] == n)
        {
            found = 1;
            break;
        }
    }
    if (found)
        printf("The given number is found at %d", i);
    else
        printf("Please enter a valid number.");
}
