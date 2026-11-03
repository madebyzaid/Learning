# include <stdio.h>

int sum(int a, int b) {
    return (a + b);
}

int main(){
    int a,b;
    printf("Enter the value of a : ");
    scanf("%d", &a);
    printf("Enter the value of b : ");
    scanf("%d", &b);

    printf("a < b  = %d\n", a < b);
    printf("a > b  = %d\n", a > b);
    printf("a <= b = %d\n", a <= b);
    printf("a >= b = %d\n", a >= b);
    printf("a == b = %d\n", a == b);
    printf("a != b = %d\n", a != b);
    return 0;
}