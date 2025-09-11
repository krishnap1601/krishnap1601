#include <stdio.h>
#include <math.h>
int main() {
 double x;
 printf("Enter a number: ");
 scanf("%lf", &x);
 printf("Square root = %.2lf\n", sqrt(x));
 printf("Absolute value = %.2lf\n", fabs(x));
 return 0;
}
