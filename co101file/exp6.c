#include<stdio.h>

int main() {
int a,b;
printf("Using logical operators on a and b\n");
printf("Enter a: ");
scanf("%d", &a);
printf("Enter b: ");
scanf("%d", &b);
printf("a && b = %d\n", a&&b);
printf("a || b = %d\n", a||b);
printf("!(a) = %d\n", !(a));
printf("!(b) = %d\n", !(b));
return 0;
}