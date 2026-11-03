#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int r1, c1, r2, c2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Multiplication not possible: columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    int A[r1][c1], B[r2][c2], P[r1][c2];

    printf("Enter elements of first matrix:\n");
    inputMatrix(r1, c1, A);
    printf("Enter elements of second matrix:\n");
    inputMatrix(r2, c2, B);

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            P[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Product of the two matrices:\n");
    displayMatrix(r1, c2, P);
    return 0;
}