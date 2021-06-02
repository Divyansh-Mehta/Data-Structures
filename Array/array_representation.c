#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    // Method 1  (All in Stack)

    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}}; // Creating

    for (i = 0; i < 3; i++) // Accessing
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Method 2 (Partially in Stack and Partially in Heap)

    int *B[3]; // Creating

    B[0] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
    B[3] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++) // Accessing  (Default values filled will be garbage)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Method 3 (Whole in heap)

    int **C;

    C = (int **)malloc(3 * sizeof(int *));

    *(C + 0) = (int *)malloc(4 * sizeof(int));
    *(C + 1) = (int *)malloc(4 * sizeof(int));
    *(C + 2) = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++) // Filling Values
    {
        for (j = 0; j < 4; j++)
        {
            *(*(C + i) + j) = i + j;
        }
    }

    for (i = 0; i < 3; i++) // Accessing
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", *(*(C + i) + j));
        }
        printf("\n");
    }

    return 0;
}