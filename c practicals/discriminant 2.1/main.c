#include <stdio.h>
#include <math.h>
int main() {
 float a, b, c, discriminant, root1, root2, realPart, imagPart;
 printf("Enter coefficients a, b and c: ");
 scanf("%f%f%f", &a, &b, &c);
 discriminant = b * b - 4 * a * c;
 if (discriminant > 0) {
 root1 = (-b + sqrt(discriminant)) / (2 * a);
 root2 = (-b - sqrt(discriminant)) / (2 * a);
 printf("Real and distinct roots: %.2f and %.2f", root1, root2);
 } else if (discriminant == 0) {
 root1 = -b / (2 * a);
 printf("Real and equal roots: %.2f and %.2f", root1, root1);
 } else {
 realPart = -b / (2 * a);
 imagPart = sqrt(-discriminant) / (2 * a);
 printf("Complex roots: %.2f + %.2fi and %.2f - %.2fi",
 realPart, imagPart, realPart, imagPart);
 }
 return 0;
}
