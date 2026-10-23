#include <stdio.h>
#include "matrix.h"

int main(void)
{
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c], T[c][r];

    printf("Enter elements of the matrix:\n");
    inputMatrix(r, c, A);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            T[j][i] = A[i][j];
        }
    }

    printf("Original matrix:\n");
    displayMatrix(r, c, A);
    printf("Transpose of the matrix:\n");
    displayMatrix(c, r, T);
    return 0;
}