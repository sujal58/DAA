#include <stdio.h>

int main(void) {
    int x, y, gcd;
    printf("Enter two numbers to find the GCD:\n");
    scanf("%d %d", &x, &y);

    for(int i = 1; i <= x && i <= y; i++) {
        if(x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    printf("GCD of given two numbers is: %d", gcd);

}
