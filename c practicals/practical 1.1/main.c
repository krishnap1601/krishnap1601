#include <stdio.h>
int main() {
 float P, R, T, SI;
 printf("Enter Principal amount: ");
 scanf("%f", &P);
 printf("Enter Rate of Interest: ");
 scanf("%f", &R);
 printf("Enter Time (in years): ");
 scanf("%f", &T);
 SI = (P * R * T) / 100;
 printf("Simple Interest = %.2f", SI);
 return 0;
}
