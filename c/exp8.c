# include <stdio.h>

int main(){
    int a,b;
    printf("Enter the value of a : ");
    scanf("%d", &a);
    printf("Enter the value of b : ");
    scanf("%d", &b);

    printf("AND = %d\n", a & b);
    printf("OR = %d\n", a | b);
    printf("XOR = %d\n", a ^ b);
    printf("NOT = %d\n", ~a);
    printf("Left Shift = %d\n", a << 1);
    printf("Right Shift = %d\n", a >> 1);

    return 0;
}