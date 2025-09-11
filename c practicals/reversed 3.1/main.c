#include <stdio.h>
int main() {
 int num, rev = 0, rem;

 printf("Enter a number: ");
 scanf("%d", &num);

 // Store original number for display
 int original = num;

 while (num != 0) {
 rem = num % 10; // Extract last digit
 rev = rev * 10 + rem; // Build reversed number
 num /= 10; // Remove last digit
 }

 printf("Original number: %d\n", original);
 printf("Reversed number: %d\n", rev);

 return 0;
}
