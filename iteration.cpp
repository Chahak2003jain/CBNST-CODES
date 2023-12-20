#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (cos(x) - 3 * x + 1);
}

float g(float x)
{
    return (cos(x) + 1) / 3;
}

float h(float x)
{
    return -sin(x) / 3;
}
int main()
{
    int flag = 0, count = 0;

    float x0, x, err,val;

    printf("Enter the allowed error\n");

    scanf("%f", &err);

    do
    {
        printf("Enter the value of x0\n");
        scanf("%f", &x0);

        if (h(x0) < 1)
        {
            flag = 1;
        }
    } while (flag != 1);

    printf("Iteration\t\tx\t\tx1\t\tf(x1)\n");

    do
    {
        count ++;
        x = g(x0);

         printf("%d\t%f\t%f\t%f\n", count, x0, x, g(x));

                x0 = x;
                val = g(x0);

    }while(fabs(f(val)-f(x))>err);

 printf("Root of equation after %d iterations is %f\n", count, x);
 return 0;
}