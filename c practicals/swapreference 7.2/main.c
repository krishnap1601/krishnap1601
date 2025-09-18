#include <stdio.h>
#include <stdlib.h>

void swapreference(int *x, int *y)  {
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
     printf("inside swaprefernce - x: %d, y: %d\n", *x, *y);
     }

int main()
{
    int a, b;

    printf("enter two number: ");
    scanf("%d %d", &a, &b);

    printf("before swapreference - a: %d, b: %d\n", a, b);
    swapreference(&a, &b);
     printf("after swapreference - a: %d, b: %d\n", a, b);

    return 0;
}
