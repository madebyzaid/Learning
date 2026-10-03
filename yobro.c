#include <stdio.h>
int main() {
    int N, i;
    printf("Enter N: ");
    scanf("%d", &N);
    int a[N];
    for (i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);          // & is needed
    }
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}