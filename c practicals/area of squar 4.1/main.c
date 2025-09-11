#include <stdio.h>
int area(int side) {
 return side * side;
}
int main() {
 int side;
 printf("Enter the side of the square: ");
 scanf("%d", &side);
 printf("Area of square = %d", area(side));
 return 0;
}
