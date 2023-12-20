#include <stdio.h>
#include <math.h>
#include<stdlib.h>


int main()
{
    int n;

    printf("Enter the no. of unknowns\n");
    scanf("%d", &n);

    // Reading augmented matrix
    float arr[n][n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        float divisor = arr[i][i];

        if (divisor == 0)
        {
            printf("Division by zero encountered. Gauss-Jordan elimination failed.\n");
            exit(0);
        }

        for (int j = 0; j < n + 1; j++)
        {
            arr[i][j] = arr[i][j] / divisor; // Scale row i
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                float ratio = arr[j][i];

                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] = arr[j][k] - ratio * arr[i][k]; // Eliminate other rows
                }
            }
        }
    }

   
    // Printing matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }

    float x[n];

    for (int i = 0; i < n; i++)
    {
        x[i] = arr[i][n]; // Extract solutions
    }

    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}
