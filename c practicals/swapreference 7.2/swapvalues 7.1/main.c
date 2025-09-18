#include <stdio.h>

void swapvalue(int a, int b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
   printf("insie swapvalue - a: %d, b: %d\n", a, b);
}

int main() {
    int a, b;
    printf("enter two numbers:");
    scanf("%d %d", &a, &b);

     printf("before swapvalue - a: %d, b: %d\n", a, b);
     swapvalue(a, b);
     printf("after swapvalue - a: %d, b: %d\n", a, b);

     return 0;

      }
