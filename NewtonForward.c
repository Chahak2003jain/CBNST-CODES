#include <stdio.h>
#include <math.h>

int fact(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
    {
        f = f * i;
    }

    return f;
}
int main()
{
    int n, ch = 30;
    float x, y, h, p, px = 1;
    printf("Enter the number of data:\n");
    scanf("%d", &n);

    float arr[10][11];
    printf("Enter the values of x\n");
    printf("X\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][0]);
    }

    printf("\nEnter the values of y\n");
    printf("Y\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][1]);
    }
    printf("\n");

    printf("Enter the value of x for function f(x)");
    scanf("%f", &x);

    // forming difference table
    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
        }
    }

    // printing table
    printf("Difference table is as follows\n");
    printf("x\ty");
    for (int i = 0; i <= n - 2; i++)
    {
        printf("\t%c^%dy", ch, i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n + 1 - i; j++)
        {
            printf("\t%.4f", arr[i][j]);
        }
    }

    // calculating value of f(x) for x
    h = arr[1][0] - arr[0][0];
    p = (x - arr[0][0]) / h;
    y = arr[0][1];
    for (int i = 1; i < n; i++)
    {
        px = px * (p - (i - 1));
        y = y + (arr[0][i + 1] * px) / fact(i);
    }

    printf("\nValue of function for x = %f is %f\n", x, y);
}