#include <stdio.h>

int main(void)
{
float m1, m2, m3, m4, m5, m6, average;
printf("Enter marks of 6 subjects:\n");
scanf("%f", &m1);
scanf("%f", &m2);
scanf("%f", &m3);
scanf("%f", &m4);
scanf("%f", &m5);
scanf("%f", &m6);
average = (m1 + m2 + m3 + m4 + m5 + m6) / 6;
printf("Average marks = %f\n", average);
return 0;
}