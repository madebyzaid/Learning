#include <stdio.h>

int main()
{
printf("Enter two integers: ");
int a, b;
scanf("%d %d", &a, &b);
printf("Addition: %d + %d = %d\n", a, b, a + b);
printf("Subtraction: %d - %d = %d\n", a, b, a - b);
printf("Multiplication: %d * %d = %d\n", a, b, a * b);
printf("Division: %.2f / %.2f = %.2f\n", (float)a, (float)b, (float)a / (float)b);
printf("Remainder: %d %% %d = %d\n", a, b, a % b);
}