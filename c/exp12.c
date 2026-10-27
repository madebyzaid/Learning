#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c], B[r][c], C[r][c];

    printf("Enter elements of first matrix:\n");
    inputMatrix(r, c, A);
    printf("Enter elements of second matrix:\n");
    inputMatrix(r, c, B);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Sum of the two matrices:\n");
    displayMatrix(r, c, C);
    return 0;
}