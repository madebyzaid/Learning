#include <stdio.h>

double fact(int n)
{
    double f = 1;
    for (int i = 2; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

double power(double x, int n)
{
    double p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * x;
    }
    return p;
}

double exp_x(double x, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + (power(x, i) / fact(i));
    }
    return sum;
}

int main(void)
{
    double x;
    int n;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("e^%f using Taylor series = %f\n", x, exp_x(x, n));
    return 0;
}