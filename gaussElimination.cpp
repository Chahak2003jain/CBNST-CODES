#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("Enter the no. of unknowns\n");
    scanf("%d", &n);

    float arr[n][n + 1];

    printf("Enter the values\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    // appling ge

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float r = arr[j][i] / arr[i][i];

            for (int k = 0; k < n + 1; k++)
            {
                arr[j][k] = arr[j][k] - r * arr[i][k];
            }
        }
    }

    //checking failure
    for(int i = 0;i<n;i++)
    {
        if(arr[i][i] == 0)
        {
            printf("It failed\n");
            exit(0);
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }

    float x[n];

    x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = arr[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] = x[i] - x[j] * arr[i][j];
        }

        x[i] = x[i] / arr[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("x = %f\n", x[i]);
    }
}