#include <stdio.h>
int main() {
 int num;
 printf("Enter a number: ");
 scanf("%d", &num);
 if (num < 0)
 goto error;
 printf("You entered a valid number: %d\n", num);
 return 0;
error:
 printf("Error: Negative number not allowed.\n");
 return 1;
}
