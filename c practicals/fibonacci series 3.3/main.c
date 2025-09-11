#include <stdio.h>
int main() {
 int n, a = 0, b = 1, next, i;

 printf("Enter number of terms: ");
 scanf("%d", &n);

 if (n <= 0) {
 printf("Please enter a positive number.\n");
 }
 else if (n == 1) {
 printf("Fibonacci Series: %d\n", a);
 }
 else {
 printf("Fibonacci Series: %d %d ", a, b);
 for (i = 3; i <= n; i++) {
 next = a + b;
 printf("%d ", next);
 a = b; // Update previous term
 b = next; // Update current term
 }
 printf("\n");
 }

 return 0;
}
